#include <Arduino.h>

#include "tui.h"


const char* kCursorBackward = {"\033["};
const char* kCursorDown = {"\033["};
const char* kCursorForward = {"\033["};
const char* kCursorHome = {"\033[H"};
const char* kCursorPosition = {"\033["};
const char* kCursorUp = {"\033["};
const char* kClearLine =  {"\033["};
const char* kClearScreen = {"\033["};
const uint8_t kIndexFirstColumn = 1;
const uint8_t kIndexFirstLine = 1;
const uint8_t kNumberOfColumns = 80;
const uint8_t kNumberOfLines = 24;
const uint8_t kIndexPowerOrCommand = 0;
const uint8_t kIndexIndividualOrBroadcast = 0;

void DrawHorizontalLine(void) {
  Serial.print("+");
  for (int i = 78; i > 0; i--) {
    Serial.print("-");
  }
  Serial.print("+");
}

void DrawMiddleLine(void) {
  Serial.print("|");
  for (int i = 78; i > 0; i--) {
    Serial.print(" ");
  }
  Serial.println("|");
}

uint8_t BufferToInt() {
  unsigned char buffer[3] = {0x30 , 0x30, 0x30};
  unsigned char c = ' ';
  uint8_t value = 0;
  Serial.print("\033[20;9H");
  Serial.print("Please press enter the number: ");
  while (1) {
    while (Serial.available() == 0);
    uint8_t incoming_byte = Serial.read();
    if (incoming_byte == 0x0D) {
      value = 100 * (buffer[2] - 0x30) + 10 * (buffer[1] - 0x30) + buffer[0] - 0x30;
      Serial.print("\033[20;9H");
      Serial.print("Sie haben ");
      Serial.print(value);
      Serial.println("eingegeben.");
      return value;
    }
    Serial.print(incoming_byte);
    buffer[2] = buffer[1];
    buffer[1] = buffer[0];
    buffer[0] = incoming_byte;
    Serial.print("\033[20;39H");
//    Serial.print(buffer[0]);
//    Serial.print(buffer[1]);
//    Serial.print(buffer[2]);

  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.print("\033[2J");
  Serial.print("\033[H");
  DrawHorizontalLine();
  Serial.print("\n\r");

  for (int j = 22; j > 0; j--) {
    DrawMiddleLine();
  }

  DrawHorizontalLine();

  Serial.print("\033[3;9H");
  Serial.print("Uart-Dali-Interface");

  Serial.print("\033[6;9H");
  Serial.print("Addess (s): ");
  Serial.print("\033[11;40H");
  Serial.print("0");

  Serial.print("\033[15;9H");
  Serial.print("Value is intensity (i): ");
  Serial.print("\033[15;40H");
  Serial.print("x");

  Serial.print("\033[15;9H");
  Serial.print("Value is intensity (i): ");
  Serial.print("\033[15;40H");
  Serial.print(" ");

  Serial.print("\033[13;9H");
  Serial.print("Value (v): ");
  Serial.print("\033[13;40H");
  Serial.print("0");

  Serial.print("\033[15;9H");
  Serial.print("Value is intensity (p): ");
  Serial.print("\033[15;40H");
  Serial.print("x");

  Serial.print("\033[17;9H");
  Serial.print("Value is command (c): ");
  Serial.print("\033[17;40H");
  Serial.print(" ");

  Serial.print("\033[20;9H");
  Serial.print("Please press a, v, c or i");
}

void loop() {
  uint8_t address;
  uint8_t value;
  bool command;
  if (Serial.available() > 0) {
    uint8_t incoming_byte = Serial.read();
    switch (incoming_byte) {
      case 'a':
      case 'A':
        address = BufferToInt();
        break;
      case 'v':
      case 'V':
        break;
      case 'i':
      case 'I':
        Serial.print("\033[15;40H");
        Serial.print("x");
        Serial.print("\033[17;40H");
        Serial.print(" ");
        break;
      case 'c':
      case 'C':
        Serial.print("\033[15;40H");
        Serial.print(" ");
        Serial.print("\033[17;40H");
        Serial.print("x");
        break;
      default:
        break;
    }
  }
}
