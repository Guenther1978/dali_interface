///
// @file
///

#ifndef DALIINTERFACE_LIGHT_TUI
#define DALIINTERFACE_LIGHT_TUI

//#include <xc.h>
//#include <stdint.h>
//#include <stdio.h>
#include <string.h>
//#include "uart_mocker.h"
//#include "./mcc_generated_files/uart/uart1.h"
//#include "./mcc_generated_files/uart/uart2.h"

const char* kCaption = {"USB-Dali-Interface"};
const char* kNumber = {"Number"};
const char* kValue = {"Value"};
const char* kReception = {"Reception"};
const char* kMessage = {"Message"};
const char* kChoose = {"Write number (n), write value (v) or send data (s)!"};
const char* kInputNumber = {"Write number of the light!"};
const char* kInputValue = {"Write intensity or command!"};
const char* kSending = {"Sending Bytes: "};

const char* kCursorBackward = {"\0x1B"};
const char* kCursorDown = {"\0x18"};
const char* kCursorForward = {"\0x18"};
const char* kCursorPosition = {"\0x18"};
const char* kCursorUp = {"\0x18"};

const uint8_t kBufferSizeCommand = 16;
const uint8_t kBufferSizeNumber = 4;
const uint8_t kBufferSizeValue = 4;
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

typedef enum {
  CHOOSE_ACTION,
  READ_NUMBER,
  READ_VALUE,
  RECEIVE,
  SEND
} State;

typedef struct {
  State state;
  unsigned char buffer_number[3];
  unsigned char buffer_value[3];
  unsigned char buffer_command[16];
  uint8_t number;
  uint8_t value;
} TuiFsm;

void DrawHorizontalLine(TuiFsm*);

void DrawVerticalLine(TuiFsm*);

void MoveCursorHome(TuiFsm*);

void InitTuiFsm(TuiFsm*);

void InitMessage(TuiFsm*);

void InitReadNumber(TuiFsm*);

void InitReadValue(TuiFsm*);

void ShowDaliAnswer(TuiFsm*, uint8_t);

void MoveCursorToPosition(uint8_t, uint8_t, TuiFsm*);

void ClearScreen(TuiFsm*);

void ClearLine(TuiFsm*);

void ClearBuffer(unsigned char *, unsigned char);

void HandleChar(char, TuiFsm*);

#endif // DALIINTERFACE_LIGHT_TUI