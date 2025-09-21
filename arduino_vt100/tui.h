///
// @file
///

#ifndef DALIINTERFACE_LIGHT_TUI
#define DALIINTERFACE_LIGHT_TUI

#include <stdbool.h>
#include <stdint.h>

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

typedef struct tui {
  unsigned char buffer[16],
  uint8_t pointer = 0,
}

typedef struct Point {
  uint8_t column;
  uint8_t line;
};

typedef struct Line {
  struct Point;
  uint8_t length;
};

typedef struct Rectangle {
  struct Point;
  uint8_t colums;
  uint8_t lines;
};

void DrawCorner(void);
void DrawHorizontalLineFromLeft2Right(uint8_t);
void DrawHorizontalLineFromRight2Left(uint8_t);
void DrawBlankRectangle();
void DrawRectangle(uint8_t, uint8_t);
void DrawVerticalLineFromBottom2Top(uint8_t);
void DrawVerticalLineFromTop2Bottom(uint8_t);
void MoveCursorDown(void);
void MoveCursorForward(void);
void MoveCursorBackward(void);
void MoveCursorUp(void);
void PrintBottomOrUpperLine(uint8_t);
void PrintMiddleLine(uint8_t);
void SetCursor(uint8_t, uint8_t);

#endif // DALIINTERFACE_LIGHT_TUI
