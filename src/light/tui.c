#include "tui.h"
#include "../uart/uart1.h"

void DrawCorner(void) {
  UART1_write('+');
}

void DrawHorizontalLineLeft2Right(uint8_t lenght) {
  UART1_write('-');
  for (int i = length - 1; i > 0; i--) {
    MoveCursorForward();
    UART1_write('-');
  }
}

void DrawHorizontalLineRight2Left(uint8_t lenght) {
  UART1_write('-');
  for (int i = length - 1; i > 0; i--) {
    MoveCursorBackward();
    UART1_write('-');
  }
}

void DrawVerticalLineBottom2Top(uint8_t lenght) {
  UART1_write('|');
  for (int i = length - 1; i > 0; i--) {
    MoveCursorUp();
    UART1_write('|');
  }
}

void DrawVerticalLineTop2Bottom(uint8_t lenght) {
  UART1_write('|');
  for (int i = length - 1; i > 0; i--) {
    MoveDursorDown();
    UART1_write('|');
  }
}

void MoveCursorDown(void) {
  for(uint8_t i = 0; i < strlen(kCursorDown); i++) {
      UART1_write(msg[i]);
  }
}

void MoveCursorForward(void) {
  for(uint8_t i = 0; i < strlen(kCursorForward); i++) {
      UART1_write(msg[i]);
  }
}

void MoveCursorBackward(void) {
  for(uint8_t i = 0; i < strlen(kCursorBackward); i++) {
      UART1_write(msg[i]);
  }
}

void MoveCursorUp(void) {
  for(uint8_t i = 0; i < strlen(kCursorUp); i++) {
      UART1_write(msg[i]);
  }
}
