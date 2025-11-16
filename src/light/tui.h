///
// @file
///

#ifndef DALIINTERFACE_LIGHT_TUI
#define DALIINTERFACE_LIGHT_TUI

//#include <xc.h>
//#include <stdint.h>
//#include <stdio.h>
#include <string.h>
#include "../mcc_generated_files/uart/uart1.h"
//#include "../mcc_generated_files/uart/uart2.h"

const char* kCaption = {"USB-Dali-Interface"};
const char* kNumber = {"Number"};
const char* kValue = {"Value"};
const char* kReception = {"Reception"};
const char* kMessage = {"Message"};

const char* kCursorBackward = {"\0x1B"};
const char* kCursorDown = {"\0x18"};
const char* kCursorForward = {"\0x18"};
const char* kCursorPosition = {"\0x18"};
const char* kCursorUp = {"\0x18"};

const uint8_t kBufferSizeCommand = 16;
const uint8_t kBufferSizeNumber = 4;
const uint8_t kLineTop = 1;
const uint8_t kLineBottom = 24;
const uint8_t kColumnLeft = 1;
const uint8_t kColumnRight = 80;

const char* kCursorHome = {"\27[H"};
const char* kClearScreen = {"\27[2J"};

const uint8_t kColumnLabel = 4;
const uint8_t kColumnValue = 16;
const uint8_t kLineCaption = 3;
const uint8_t kLineNumber = 7;
const uint8_t kLineValue = 10;
const uint8_t kLineReception = 13;
const uint8_t kLineMessage = 20;

void DrawHorizontalLine(void);
void DrawVerticalLine(void);
void MoveCursorHome(void);

void DrawCorner(void);
void DrawHorizontalLineFromLeft2Right(uint8_t);
void DrawHorizontalLineFromRight2Left(uint8_t);
void DrawRectangle(uint8_t, uint8_t);
void DrawVerticalLineFromBottom2Top(uint8_t);
void DrawVerticalLineFromTop2Bottom(uint8_t);
void MoveCursorDown(void);
void MoveCursorForward(void);
void MoveCursorBackward(void);
void MoveCursorUp(void);
void SetCursor(uint8_t, uint8_t);

typedef enum {
  CHOOSE_ACTION,
  READ_NUMBER,
  READ_VALUE,
  RECEIVE,
  SEND
} State;

typedef struct TuiFsm {
  State state;
  unsigned char buffer_number[3];
  unsigned char buffer_value[3];
  unsigned char buffer_command[16];
  uint8_t number;
  uint8_t value;
};

TuiFsm tui_fsm;

void InitTuiFsm(TuiFsm* tui_fsm);

void ShowDaliAnswer(TuiFsm* tui_fsm, uint8_t answer);

void InitMessage(TuiFsm* tui_fsm);

void InitReadNumber(TuiFsm* tui_fsm);

void InitReadValue(TuiFsm* tui_fsm);

void MoveCursorToPosition(uint8_t line, uint8_t column, TuiFsm* puffer);

void ClearScreen(TuiFsm* puffer);

void ClearLine(TuiFsm* puffer);

void ClearBuffer(unsigned char * buffer, unsigned char size_of_buffer);

void HandleChar(char input, TuiFsm* tui_fsm);

#endif // DALIINTERFACE_LIGHT_TUI
