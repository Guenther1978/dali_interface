#include "tui.h"
#i#include "../uart/uart1.h"

void DrawCorner(void) {
  ('+');
}

void DrawHorizontalLineLeft2Right(uint8_t lenght) {
  UART1_write('-');
  for (int i = length - 1; i > 0; i--) {
    for(uint8_t i = 0; i < strlen(kCursorForward); i++) {
      EUSART1_write(msg[i]);
    }
    UART1_write('-');
  }
}
