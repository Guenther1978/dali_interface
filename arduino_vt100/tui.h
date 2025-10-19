///
// @file
///

#ifndef _DALIINTERFACE_LIGHT_TUI
#define _DALIINTERFACE_LIGHT_TUI

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

const char ESC_HOME[] = "\x1B[H";
const char* kCursorBackward = {"\033["};
const char* kCursorDown = {"\033["};
const char* kCursorForward = {"\033["};
const char* kCursorHome = {"\033[H"};
const char* kCursorPosition = {"\033["};
const char* kCursorUp = {"\033["};
const uint8_t kIndexFirstColumn = 1;
const uint8_t kIndexFirstLine = 1;
const uint8_t kNumberOfColumns = 80;
const uint8_t kNumberOfLines = 24;

void ClearScreen(unsigned char *);

void ClearBuffer(unsigned char * buffer, unsigned char size_of_buffer) {
  for (int i = 0; i < size_of_buffer; i ++) {
    buffer[i] = ' ';
  }
}

void WriteCommand(unsigned char *puffer) {
  puffer[0] = 0x1B;
  puffer[1] = '[';
}

void ClearScreen(unsigned char * puffer) {
  ClearBuffer(puffer, 16);
  WriteCommand(puffer);
  puffer[2] = 'H';
  puffer[3] = 0;
}

void MoveCursorToPosition(uint8_t x, uint8_t y, unsigned char* puffer) {
  puffer[0] = 27;
  puffer[1] = '[';
  sprintf(puffer+2, "%d;%dH",y,x); 
}

void CopyCommand(unsigned char *puffer, const char* command) {
  strcpy(*puffer, command);
}

#endif // _DALIINTERFACE_LIGHT_TUI
