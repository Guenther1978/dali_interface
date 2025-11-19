#include <stdint.h>
#include <stdio.h>

void UART1_Write(uint8_t character) {
  puts(character);
}

unsigned char UART1_Read(void) {
  return 0x66;
}

void UART2_Write(uint8_t character) {
  putchar(character);
}

unsigned char UART2_Read(void) {
  return 0x67;
}
