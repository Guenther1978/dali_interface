#include <Arduino.h>

unsigned char buffer[16];

const uint8_t kBufferSize = 16;
const uint8_t kLineTop = 1;
const uint8_t kLineBottom = 24;
const uint8_t kColumnLeft = 1;
const uint8_t kColumnRight = 80;
const char* kCursorHome = {"\27[H"};
const char* kClearScreen = {"\27[2J"};

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
    buffer[i] = ' ';
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial);

  ClearScreen(buffer);
  Serial.write(buffer, kBufferSize);

  for (uint8_t i = kLineTop + 1; i < kLineBottom; i++) {
    MoveCursorToPosition(i, kColumnLeft, buffer);
    Serial.write(buffer, kBufferSize);
    Serial.write('|');
    MoveCursorToPosition(i, kColumnRight, buffer);
    Serial.write(buffer, kBufferSize);
    Serial.write('|');
  }

  delay(1000);

  for (uint8_t i = kColumnLeft + 1; i < kColumnRight; i++) {
    MoveCursorToPosition(kLineBottom, i, buffer);
    Serial.write(buffer, kBufferSize);
    Serial.write('-');
    MoveCursorToPosition(kLineTop, i, buffer);
    Serial.write(buffer, kBufferSize);
    Serial.write('-');
  }

  delay(1000);

  MoveCursorToPosition(kLineTop, kColumnLeft, buffer);
  Serial.write(buffer, kBufferSize);
  Serial.write('+');

  MoveCursorToPosition(kLineBottom, kColumnLeft, buffer);
  Serial.write(buffer, kBufferSize);
  Serial.write('+');

  MoveCursorToPosition(kLineTop, kColumnRight, buffer);
  Serial.write(buffer, kBufferSize);
  Serial.write('+');

  MoveCursorToPosition(kLineBottom, kColumnRight, buffer);
  Serial.write(buffer, kBufferSize);
  Serial.write('+');
}

void loop() {
  uint8_t address;
  uint8_t value;
  bool command;

  if (Serial.available() > 0) {
    Serial.read();
    MoveCursorToPosition(3, 20, buffer);
    Serial.write(buffer, kBufferSize);

    Serial.println("Hallo Welt");
  }
}
