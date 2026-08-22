#include "sapi.h"

#define BAUD_DEBUG 115200
#define PIR_PIN    GPIO1

int main(void)
{
   boardConfig();

   uartInit(UART_USB, BAUD_DEBUG);

   // Configurar pin como entrada con pull-down
   gpioInit(PIR_PIN, GPIO_INPUT_PULLUP);

   while(TRUE) {
      bool_t v = gpioRead(PIR_PIN);

      uartWriteString(UART_USB, v ? "1\r\n" : "0\r\n");
      delay(500);
   }
}
