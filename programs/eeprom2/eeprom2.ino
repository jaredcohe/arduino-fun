#include <EEPROM.h>
# https://www.coursera.org/learn/arduino-platform/lecture/iafeK/lecture-3-1-serial-on-arduino

read from serial

void setup() {
  int addr;
  Serial.begin(9600);
  for (addr=0; addr<1024; addr++) {
    EEPROM.write(addr, addr);
  }
  for (addr=0; addr<1024; addr++) {
     Serial.print(EEPROM.read(addr), DEC);
     Serial.print("\n");
  }
  Serial.print("END SETUP");
}

void loop() {
  
}

/*
masking
int bigData;
byte littleData;
void setup() {
  Serial.begin(9600);
  littleData = bigData & 0xFF;
  EEPROM.write(0, littleData);
  littleData = (bigData >> 8) & OxFF;
  EEPROM.write(1, littleData);
}
*/

