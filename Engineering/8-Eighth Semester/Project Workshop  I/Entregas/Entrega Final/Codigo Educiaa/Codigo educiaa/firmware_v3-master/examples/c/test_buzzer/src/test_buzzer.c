#include "sapi.h"

static void beep_soft_gpio7(uint32_t ms)
{
   uint32_t t = ms; // aprox 2ms por ciclo
   while(t >= 2) {
      gpioWrite(GPIO7, ON);
      delay(1);
      gpioWrite(GPIO7, OFF);
      delay(1);
      t -= 2;
   }
   gpioWrite(GPIO7, OFF);
}

int main(void)
{
   boardConfig();

   uartConfig(UART_USB, 115200);

   gpioInit(GPIO7, GPIO_OUTPUT);
   gpioWrite(GPIO7, OFF);

   bool pressed_prev = false;

   uartWriteString(UART_USB, "Listo. Apreta TEC1 para hacer beep.\r\n");

   while(TRUE) {

      // TEC1 suele ser active-low: apretado => 0
      bool pressed = (gpioRead(TEC1) == 0);

      // Detectar flancos para imprimir una sola vez
      if(pressed && !pressed_prev) {
         uartWriteString(UART_USB, "TEC1 APRETADA\r\n");
      }
      if(!pressed && pressed_prev) {
         uartWriteString(UART_USB, "TEC1 SOLTADA\r\n");
      }
      pressed_prev = pressed;

      // Beep mientras esté apretado
      if(pressed) {
         beep_soft_gpio7(150);
         delay(50);
      } else {
         gpioWrite(GPIO7, OFF);
         delay(10);
      }
   }

   return 0;
}
