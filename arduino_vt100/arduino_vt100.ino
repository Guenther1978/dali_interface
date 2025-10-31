#include <Arduino.h>

unsigned char buffer[16];

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
const uint8_t kLineMessage = 20;

typedef enum {
  CHOOSE_ACTION,
  READ_NUMBER,
  READ_VALUE,
  SEND
} State;

typedef struct TuiFsm {
  //  uint8_t state;
  State state;
  unsigned char buffer_number[3];
  unsigned char buffer_value[3];
  unsigned char buffer_command[16];
  uint8_t number;
  uint8_t value;
};

TuiFsm *tui_fsm;

void InitTuiFsm(TuiFsm* tui_fsm) {
  tui_fsm->state = CHOOSE_ACTION;
}


void InitReadNumber(TuiFsm* tui_fsm) {
  tui_fsm->state = READ_NUMBER;
  tui_fsm->number = 0;
  for (uint8_t i = 0; i < 3; i++) {
    tui_fsm->buffer_number[i] = '0';
  }
  MoveCursorToPosition(kLineNumber, kColumnValue, tui_fsm->buffer_command);
}

void InitReadValue(TuiFsm* tui_fsm) {
  tui_fsm->state = READ_VALUE;
  tui_fsm->value = 0;
  for (uint8_t i = 0; i < 3; i++) {
    tui_fsm->buffer_value[i] = '0';
  }
  MoveCursorToPosition(kLineValue, kColumnValue, tui_fsm->buffer_command);
}

void MoveCursorToPosition(uint8_t line, uint8_t column, unsigned char* puffer) {
  //  puffer[0] = 27;
  //  puffer[1] = '[';
  //  sprintf(puffer+2, "%d;%dH",y,x);
  // the first specifying the line position and the second specifying the column position
  sprintf(puffer, "%c[%d;%dH", 27, line, column);
}

void ClearScreen(unsigned char* puffer) {
  sprintf(puffer, "%c[2J", 27);
}


void ClearBuffer(unsigned char * buffer, unsigned char size_of_buffer) {
  for (int i = 0; i < size_of_buffer; i ++) {
    buffer[i] = '0';
  }
}

void HandleChar(char input, TuiFsm* tui_fsm) {
  if ((input >= '0') && (input <= '9')) {
    switch (tui_fsm->state) {
      case READ_NUMBER:
        tui_fsm->buffer_number[2] = tui_fsm->buffer_number[1];
        tui_fsm->buffer_number[1] = tui_fsm->buffer_number[0];
        tui_fsm->buffer_number[0] = input;
        break;
      case READ_VALUE:
        tui_fsm->buffer_value[2] = tui_fsm->buffer_value[1];
        tui_fsm->buffer_value[1] = tui_fsm->buffer_value[0];
        tui_fsm->buffer_value[0] = input;
        break;
      default:
        break;
    }
  }
  if ((input == 'N') || (input == 'n')) {
    InitReadNumber(tui_fsm);
  }
  if ((input == 'V') || (input == 'v')) {
    InitReadValue(tui_fsm);
  }
    if ((input == 'S') || (input == 's')) {
      tui_fsm->number = atoi(tui_fsm->buffer_number);
      tui_fsm->value = atoi(tui_fsm->buffer_value);

      tui_fsm->state = CHOOSE_ACTION;
  }
}


void setup() {
  Serial.begin(9600);
  while (!Serial);

  ClearScreen(buffer);
  Serial.write(buffer, kBufferSizeCommand);

  for (uint8_t i = kLineTop + 1; i < kLineBottom; i++) {
    MoveCursorToPosition(i, kColumnLeft, buffer);
    Serial.write(buffer, kBufferSizeCommand);
    Serial.write('|');
    MoveCursorToPosition(i, kColumnRight, buffer);
    Serial.write(buffer, kBufferSizeCommand);
    Serial.write('|');
  }

  for (uint8_t i = kColumnLeft + 1; i < kColumnRight; i++) {
    MoveCursorToPosition(kLineBottom, i, buffer);
    Serial.write(buffer, kBufferSizeCommand);
    Serial.write('-');
    MoveCursorToPosition(kLineTop, i, buffer);
    Serial.write(buffer, kBufferSizeCommand);
    Serial.write('-');
  }

  MoveCursorToPosition(kLineTop, kColumnLeft, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.write('+');

  MoveCursorToPosition(kLineBottom, kColumnLeft, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.write('+');

  MoveCursorToPosition(kLineTop, kColumnRight, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.write('+');

  MoveCursorToPosition(kLineBottom, kColumnRight, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.write('+');

  MoveCursorToPosition(kLineCaption, kColumnValue, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.print("USB-Dali-Converter");

  for (uint8_t i = kColumnValue - 1; i < (19)  ; i++) {
    MoveCursorToPosition(kLineCaption + 1, i, buffer);
    Serial.write(buffer, kBufferSizeCommand);
    Serial.write('-');
  }

  MoveCursorToPosition(kLineNumber, kColumnLabel, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.print("Number");

  MoveCursorToPosition(kLineValue, kColumnLabel, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.print("Value");

  MoveCursorToPosition(kLineMessage, kColumnLabel, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.print("Message: ");

  MoveCursorToPosition(kLineMessage, kColumnValue, buffer);
  Serial.write(buffer, kBufferSizeCommand);
  Serial.print("Write number (n), write value (v) or send data (s)");

  InitTuiFsm(tui_fsm);
}

void loop() {
  uint8_t address;
  uint8_t value;
  unsigned char char_in;
  bool command;

  if (Serial.available() > 0) {
    char_in = Serial.read();
    HandleChar(char_in, tui_fsm);
    Serial.write(tui_fsm->buffer_command, kBufferSizeCommand);
    Serial.write(tui_fsm->buffer_number, kBufferSizeNumber);
    Serial.write(tui_fsm->buffer_value, kBufferSizeNumber);


  }
}
