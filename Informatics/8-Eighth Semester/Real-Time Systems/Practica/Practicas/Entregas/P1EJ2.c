#include <htc.h>

__CONFIG(FOSC_XT & WDTE_OFF & PWRTE_OFF & CP_OFF);

#define _XTAL_FREQ 1000000UL   // 1 MHz
#define TMR0_PRELOAD 12        // ~250 ms con prescaler 1:256 y Fosc=1 MHz

volatile unsigned char titilar = 0;   // 0: ambos encendidos, 1: alternar

void main(void) {
    // Entradas / salidas
    TRISA = 0xFF;   // RA0 y RA1 como entradas (resto también entradas)
    TRISB = 0x00;   // Todo PORTB salida (usamos RB4 y RB5)

    // Estado inicial: ambos LEDs encendidos
    RB4 = 1;
    RB5 = 1;

    // Timer0: reloj interno, prescaler 1:256 asignado a TMR0
    // OPTION_REG bits (RBPU INTEDG T0CS T0SE PSA PS2 PS1 PS0)
    //                 [  0     0     0    0    0   1   1   1 ] = 0b00000111
    OPTION_REG = 0b00000111;

    // Precarga y habilitación de interrupciones
    TMR0 = TMR0_PRELOAD;
    T0IF = 0;   // limpiar flag de desborde
    T0IE = 1;   // habilitar interrupción por Timer0
    GIE  = 1;   // habilitación global de interrupciones

    // Bucle principal
    while(1) {
        // Un clic en RA0 o RA1 activa el titilado (pulsadores activos en bajo)
        if (RA0 == 0 || RA1 == 0) {
            titilar = 1;

        }

    }
}

// Interrupción
void interrupt isr(void) {
    if (T0IF) {                 // desborde de Timer0
        TMR0 = TMR0_PRELOAD;   // recargar para repetir ~250 ms
        T0IF = 0;              // limpiar flag

        if (titilar) {
            // Alternar RB4/RB5
            if (RB4) {
                RB4 = 0; RB5 = 1;
            } else {
                RB4 = 1; RB5 = 0;
            }
        }
    }
}

