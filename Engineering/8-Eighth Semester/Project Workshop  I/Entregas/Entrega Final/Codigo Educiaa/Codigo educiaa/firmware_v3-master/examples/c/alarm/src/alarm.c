#include "sapi.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum { DESARMADA=0, ARMANDO=1, ARMADA=2, DISPARO=3 } estado_t;

static estado_t estado = DESARMADA;

// Zonas habilitadas
static uint8_t zonas_mask = 0x00;

// Sensores activos
static uint8_t sensores_activos_mask = 0x00;

// Zona que disparo (1..3) o 0 si no aplica
static uint8_t disparo_zona = 0;

// Timer interno de ARMANDO (ms)
static int32_t armando_ms = 0;

// UARTs
#define UART_ESP UART_232
#define UART_DBG UART_USB

// PIRs
static gpioMap_t PIR_PIN[3] = { GPIO1, GPIO4, GPIO6 };

// Buzzer pasivo
#define BUZZER_PIN GPIO7

static char rx_line[64];
static int  rx_len = 0;

static char cmd_line[64];
static volatile bool cmd_pending = false;

//---------------------------------------------------------------------------------------------------
static bool comando_valido(const char* s){
  return (strcmp(s,"GET")==0) ||
         (strcmp(s,"ARM")==0) ||
         (strcmp(s,"DISARM")==0) ||
         (strncmp(s,"z1=",3)==0) || (strncmp(s,"z2=",3)==0) || (strncmp(s,"z3=",3)==0) ||
         (strncmp(s,"SETZ ",5)==0);
}

void uart_recibir_linea(void){
  uint8_t byte;

  // uartReadByte devuelve TRUE si habia un byte para leer
  while (uartReadByte(UART_ESP, &byte)) {

    char c = (char)byte;
    if (c == '\r') continue;

    if (c == '\n') {
      rx_line[rx_len] = 0;
      rx_len = 0;

      if (comando_valido(rx_line)) {
         
        strncpy(cmd_line, rx_line, sizeof(cmd_line) - 1);
        cmd_line[sizeof(cmd_line) - 1] = 0;
        cmd_pending = true;
         
        uartWriteString(UART_DBG, "CMD: ");
        uartWriteString(UART_DBG, cmd_line);
        uartWriteString(UART_DBG, "\r\n");
      } else {
        uartWriteString(UART_DBG, "IGN: ");
        uartWriteString(UART_DBG, rx_line);
        uartWriteString(UART_DBG, "\r\n");
      }

      continue;         
    }

    if (rx_len < (int)sizeof(rx_line) - 1) {
      rx_line[rx_len++] = c;
    } else {
      // overflow
      rx_len = 0;
    }
  }

}

//---------------------------------------------------------------------------------------------------
// Lectura PIR y detección de flancos

static uint8_t last_pir_bits = 0;

static uint8_t leer_pirs_bits(void){
  uint8_t now = 0;
  for(int i=0;i<3;i++){
    if(gpioRead(PIR_PIN[i])) now |= (1<<i);
  }
  return now;
}

/*
 * Actualiza sensores_activos_mask y entrega rising/falling
 * rising: flanco de subida
 * falling: flanco de bajada
 * Devuelve true si hubo cualquier cambio (rising o falling)
 */
static bool actualizar_sensores(uint8_t* rising, uint8_t* falling){
  uint8_t now = leer_pirs_bits();

  uint8_t r = (now & ~last_pir_bits);
  uint8_t f = (~now & last_pir_bits);

  last_pir_bits = now;
  sensores_activos_mask = now;

  if(rising)  *rising  = r;
  if(falling) *falling = f;

  return ( (r | f) != 0 );
}

static uint8_t primera_zona_en_mask(uint8_t m){
  for(int i=0;i<3;i++){
    if(m & (1<<i)) return (uint8_t)(i+1); // 1..3
  }
  return 0;
}

//---------------------------------------------------------------------------------------------------
static delay_t tBuzz;
static bool buzz_level = 0;
static bool buzz_inited = false;
static bool siren_inited = false;

static uint32_t half_cycles  = 0;
static uint32_t next_toggle_cy = 0;

static tick_t  next_sweep_ms = 0;
static int16_t freq_hz       = 900;
static int8_t  dir           = +1;

// Ajustes sirena
#define SIREN_FMIN_HZ   900
#define SIREN_FMAX_HZ   1600
#define SIREN_DF_HZ     11      // paso de frecuencia
#define SIREN_STEP_MS   2       // cada cuanto cambia la frecuencia

static inline bool ms_reached(tick_t now, tick_t due){
  return ((int32_t)(now - due) >= 0);
}

static inline bool cy_reached(uint32_t now, uint32_t due){
  return ((int32_t)(now - due) >= 0);
}

static inline uint32_t calc_half_cycles(int16_t f){
  uint64_t denom = (uint64_t)f * 2ull;
  uint64_t hc = (uint64_t)SystemCoreClock / denom;
  if(hc < 1) hc = 1;
  return (uint32_t)hc;
}

void sirena_reset(void){
  siren_inited = false;
  buzz_level = false;
  gpioWrite(BUZZER_PIN, 0);
}

void sirena_update(void){
  tick_t   now_ms = tickRead();
  uint32_t now_cy = DWT->CYCCNT;

  if(!siren_inited){
     CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
     DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

     DWT->CYCCNT = 0;
     now_cy = DWT->CYCCNT;            

     freq_hz = SIREN_FMIN_HZ;
     dir     = +1;

     half_cycles    = calc_half_cycles(freq_hz);
     next_toggle_cy = now_cy + half_cycles; 

     next_sweep_ms = now_ms + SIREN_STEP_MS;

     buzz_level = false;
     gpioWrite(BUZZER_PIN, 0);

     siren_inited = true;
   }


  if(ms_reached(now_ms, next_sweep_ms)){
    next_sweep_ms += SIREN_STEP_MS;

    freq_hz += dir * SIREN_DF_HZ;
    if(freq_hz >= SIREN_FMAX_HZ){ freq_hz = SIREN_FMAX_HZ; dir = -1; }
    if(freq_hz <= SIREN_FMIN_HZ){ freq_hz = SIREN_FMIN_HZ; dir = +1; }

    half_cycles = calc_half_cycles(freq_hz);
  }


  if(cy_reached(now_cy, next_toggle_cy)){
    next_toggle_cy += half_cycles;
    buzz_level = !buzz_level;
    gpioWrite(BUZZER_PIN, buzz_level);
  }
}
//---------------------------------------------------------------------------------------------------

bool actualizar_FSM(bool comando){
  bool changed = false;


  uint8_t rising = 0, falling = 0;
  if(actualizar_sensores(&rising, &falling)){
    changed = true; 
  }

  // si llego un comando lo prceso
  if(comando){
    if(strcmp(cmd_line, "ARM") == 0){
      if(estado != ARMANDO){
        estado = ARMANDO;
        armando_ms = 5000;
        disparo_zona = 0;
        changed = true;
      }
    }
    else if(strcmp(cmd_line, "DISARM") == 0){
      if(estado != DESARMADA){
        estado = DESARMADA;
        armando_ms = 0;
        disparo_zona = 0;
        sirena_reset();
        changed = true;
      }
    }
   else if (cmd_line[0] == 'z' && cmd_line[2] == '=' &&
            (cmd_line[1] >= '1' && cmd_line[1] <= '3')) {

     int idx = cmd_line[1] - '1';   // 0..2
     int v   = atoi(cmd_line + 3);  // 0 o 1
     uint8_t bit = (uint8_t)(1u << idx);

     uint8_t nm = zonas_mask;
     if (v) nm |= bit;
     else   nm &= (uint8_t)(~bit);

     if (nm != zonas_mask) {
       zonas_mask = nm;
       changed = true;
     }
   }
    else if(strcmp(cmd_line, "GET") == 0){
      // no cambia nada, pero el main hace "if (comando || cambio) enviar"
    }
  }

  // Lógica propia por estado (cada 30ms)
  switch(estado){

    case DESARMADA:
      // nada
      break;

    case ARMANDO:
      armando_ms -= 30;
      if(armando_ms <= 0){
        armando_ms = 0;
        estado = ARMADA;
        changed = true;
      }
      break;

    case ARMADA: {
      // el disparo se determina por flanco de subida (rising),
      // pero solo en zonas habilitadas
      uint8_t candidates = (uint8_t)(rising & zonas_mask);
      uint8_t z = primera_zona_en_mask(candidates); // 1..3
      if(z != 0){
        estado = DISPARO;
        disparo_zona = z;
        changed = true;
      }
      break;
    }

    case DISPARO:
      // se sale con DISARM
      break;
  }

  return changed;
}


//---------------------------------------------------------------------------------------------------
static const char* estado_str(estado_t e){
  switch(e){
    case DESARMADA: return "DESARMADA";
    case ARMANDO:   return "ARMANDO";
    case ARMADA:    return "ARMADA";
    case DISPARO:   return "DISPARO";
    default:        return "DESARMADA";
  }
}

/**
 * FORMATO para el ESP:
 * <estado> <mask_enable> <mask_active> <disparo_zona>
 */
void enviar_status_a_esp_y_usb(void){
  char buf[96];
  snprintf(buf, sizeof(buf), "%s %u %u %u",
           estado_str(estado),
           (unsigned)zonas_mask,
           (unsigned)sensores_activos_mask,
           (unsigned)disparo_zona);

  uartWriteString(UART_ESP, buf); uartWriteString(UART_ESP, "\n");
  uartWriteString(UART_DBG, buf); uartWriteString(UART_DBG, "\r\n");
}

//---------------------------------------------------------------------------------------------------

static delay_t t30ms;

int main(void)
{
  // 1) Inicializa la placa
  boardInit();

  // 2) UARTs
  uartConfig(UART_USB, 115200);   // debug por USB
  uartConfig(UART_232, 115200);   // UART hacia ESP

  // 3) GPIO PIR como entradas
  gpioInit(GPIO1, GPIO_INPUT_PULLDOWN);
  gpioInit(GPIO4, GPIO_INPUT_PULLDOWN);
  gpioInit(GPIO6, GPIO_INPUT_PULLDOWN);

  // 4) GPIO buzzer como salida
  gpioInit(GPIO7, GPIO_OUTPUT);
  gpioWrite(GPIO7, 0);
  sirena_reset();
   
  // 5) Inicializo lecctura de PIR para evitar falso flanco al arrancar
  last_pir_bits = leer_pirs_bits();
  sensores_activos_mask = last_pir_bits;

  // 6) Tmporizador de 30ms para FSM y UART
  delayInit(&t30ms, 30);

  enviar_status_a_esp_y_usb();

  // 7) Loop principal
  while (1) {
     
    uart_recibir_linea();
     
    if (delayRead(&t30ms)) {
      bool comando = cmd_pending;
      cmd_pending = false;
       
      bool cambio = actualizar_FSM(comando);

      if (comando || cambio) {
        enviar_status_a_esp_y_usb();
      }
    }

    if (estado == DISPARO) {
      sirena_update();
    }// la siirena se actualiza todo el tiempo si esta en disparo ya q es un buzzer psivo
  }
}
