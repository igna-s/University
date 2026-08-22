#include "sapi.h"

int main(void)
{
  boardConfig();

  uartConfig(UART_USB, 115200);  // hacia la PC (terminal)
  uartConfig(UART_232, 115200);  // P1: RS-232

  uint8_t c;
   uartWriteString(UART_USB, "holaaaaa \r\n");
   uartWriteString(UART_USB, "Listo. Apreta TEC1 para hacer beep.\r\n");
  while(TRUE) {
    if (uartReadByte(UART_232, &c)) {
      uartWriteByte(UART_USB, c);
    }
  }
}
