#include <Arduino.h>

#include "tui.h"

unsigned char buffer[16];
const uint8_t buffersize = 16;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.print(kCursorHome);


}

void loop() {
  uint8_t address;
  uint8_t value;
  bool command;

  if (Serial.available() > 0) {
    Serial.read();
    MoveCursorToPosition(11, 22, buffer);
    Serial.write(buffer, 16);

    for (int i = 0; i < strlen(buffer); i++) {
      Serial.print((int)buffer[i]); // Print the ASCII value of each character
      Serial.print(" ");
    }

    Serial.println("Hallo Welt");

  }

}
