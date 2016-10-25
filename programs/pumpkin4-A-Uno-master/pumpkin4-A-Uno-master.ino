/*
set Arduino UNO board for blue
set Arduino Duemilanove w/ ATmega328
Port: /dev/tty.usbmodem1411
Programmer: arduino
Overriding Baud Rate: 115200

4: added wire library i2c
*/

// libraries
#include <Servo.h> // include servo library
#include <Wire.h> // include wire i2c library

Servo servoLeft;  // Declare left servo
Servo servoRight;  // Declare right servo

const int pirInputPin = 2;
int pirState = LOW; // we start, assuming no motion detected
int pirLastState = LOW; // previous state of pin

void setup(){
  
  Serial.begin(9600);
  Serial.println("Beep");
  tone(4, 3000, 100);
  delay(100); // delay to finish tone and wait

  // PIR-robot shield
  pinMode(pirInputPin, INPUT);
  
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach left signal to pin 12

  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal
  
  Wire.begin(); // start wire communication
  
}

void loop(){

  // check for object
  pirState = digitalRead(pirInputPin); // read input value
  
  if ((pirState == HIGH) && (pirLastState == LOW))
  {
    Serial.println("MOTION");
    Serial.println(pirState);
    tone(4, 3000, 100);

    Wire.beginTransmission(5);
    Wire.write('H');
    Wire.endTransmission();
    
    // SPIN
    servoLeft.writeMicroseconds(1550);
    servoRight.writeMicroseconds(1550);
    delay(1000);
    servoLeft.writeMicroseconds(1450);
    servoRight.writeMicroseconds(1450);
    delay(1000);
    // STOP
    servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
    servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal
  }
  else if (pirState == LOW)
  {
    Serial.println("NONE");
    Serial.println(pirState);
    
    // wire communication
    Wire.beginTransmission(5);
    Wire.write('L');
    Wire.endTransmission();
  };
  pirLastState = pirState;
}

