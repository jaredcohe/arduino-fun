/*
set Arduino UNO board for blue
set Arduino Duemilanove w/ ATmega328
Port: /dev/tty.usbmodem1411
Programmer: arduino
Overriding Baud Rate: 115200
*/

#include <Wire.h>
#define BLUEPIN 8
#define REDPIN 9
#define FADESPEED 500

void setup()
{
  Serial.begin(9600);
  Serial.println("GOOO");
  
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  Wire.begin(5);
  Wire.onReceive(receiveEvent);  
}

void loop()
{

}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    char c = Wire.read();
    
    if (c == 'H')
    {
      int r, b;

      for (r = 256; r >= 0; r--) { 
        analogWrite(REDPIN, r);
        delay(FADESPEED);
      }
      for (b = 256; b >= 0; b--) {
        analogWrite(BLUEPIN, b);
        delay(FADESPEED);
      }
    }
  }
}

