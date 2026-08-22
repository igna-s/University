#include <htc.h>
__CONFIG(FOSC_XT & WDTE_OFF & PWRTE_OFF & CP_OFF);
#define _XTAL_FREQ 4000000UL

// RD6 = LE del latch D0..D7 (LSB), RD7 = LE del latch D8..D15 (MSB)
#define LE_LOW   RD6
#define LE_HIGH  RD7

static void pulse_low (void){ LE_LOW  = 1; NOP(); NOP(); LE_LOW  = 0; }
static void pulse_high(void){ LE_HIGH = 1; NOP(); NOP(); LE_HIGH = 0; }

static void init_hw(void){
    // Puertos
    TRISB = 0x00;          // PORTB -> datos a los 74LS373
    TRISD = 0x00;          // RD6/RD7 -> LE
    TRISE = 0x00;          // RE digitales (PSP deshabilitado)
    PORTB = 0x00; PORTD = 0x00; LE_LOW = 0; LE_HIGH = 0;

    // ADC: Vref = VDD, solo AN0 analógico, resultado a derecha
    ADCON1 = 0x8E;         // ADFM=1, PCFG=1110
    ADCON0 = 0b10000001;   // Fosc/32, canal 0, ADON=1

    TRISA |= 0x01;         // RA0 entrada (AN0)
    __delay_ms(10);
}

void main(void){
    init_hw();

    while(1){
        __delay_us(25);        // Tacq
        GO_DONE = 1;           // iniciar conversión
        while(GO_DONE){}       // polling

        // Mostrar 10 bits: LSB primero (D0..D7), luego MSB (D8..D15)
        PORTB = ADRESL;  pulse_low();
        PORTB = ADRESH;  pulse_high();

        __delay_ms(10);
    }
}
