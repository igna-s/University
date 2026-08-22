#include <htc.h>
#define _XTAL_FREQ 1000000

void main(void) {
    // Configuración de puertos
    TRISA = 0xFF;   // RA0 y RA1 como entradas
    TRISB = 0x00;   // RB4 y RB5 como salidas

    // Estado inicial: ambos LEDs encendidos
    PORTBbits.RB4 = 1;
    PORTBbits.RB5 = 1;

    unsigned char titilar = 0;  // bandera para modo titilante

    while(1) {
        // Detectar si se presionó RA0 o RA1 (pulsadores activos en 0)
        if ((PORTAbits.RA0 == 0) || (PORTAbits.RA1 == 0)) {
            titilar = 1; // activar modo titilante
        }

        if (titilar) {
            // Alternar LEDs cada 250 ms
            PORTBbits.RB4 = 1;
            PORTBbits.RB5 = 0;
            __delay_ms(250);

            PORTBbits.RB4 = 0;
            PORTBbits.RB5 = 1;
            __delay_ms(250);
        }
    }
}
