///
// @file
///

#ifndef DALIINTERFACE_LIGHT_TUI
#define DALIINTERFACE_LIGHT_TUI

#include <stdint.h>

const char* kCursorBackward = {"\0x1B"};
const char* kCursorDown = {"\0x18"};
const char* kCursorForward = {"\0x18"};
const char* kCursorPosition = {"\0x18"};
const char* kCursorUp = {"\0x18"};

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

#endif // DALIINTERFACE_LIGHT_TUI
