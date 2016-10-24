/*
set Arduino UNO board for blue
set Arduino Duemilanove w/ ATmega328
Port: /dev/tty.usbmodem1411
Programmer: arduino
Overriding Baud Rate: 115200
*/

// libraries
#include <Servo.h> // Include servo library

Servo servoLeft;  // Declare left servo
Servo servoRight;  // Declare right servo

const int pirInputPin = 2;
int pirState = LOW; // we start, assuming no motion detected
int pirLastState = LOW; // previous state of pin
//int pirStatus = 0; // variable for reading the pin status
//int pirLastStatus = 0; // previous status of pin

void setup(){
  
  Serial.begin(9600);
  Serial.println("Beep");
  tone(4, 3000, 100);
  delay(100); // delay to finish tone and wait

  // PIR-robot shield
  pinMode(pirInputPin, INPUT);
  //pinMode(pirOutputPin, OUTPUT);
  
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach left signal to pin 12

  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal
  
}

void loop(){

  // check for object
  pirState = digitalRead(pirInputPin); // read input value
  
  if ((pirState == HIGH) && (pirLastState == LOW))
  {
    Serial.println("MOTION");
    Serial.println(pirState);
    tone(4, 3000, 100);
    
    // WRITE TO OUTPUT
    //digitalWrite(pirOutputPin, HIGH); // turn LED on
    //digitalWrite(pirOutputPin, LOW); // turn LED on
    
    // SPIN
    servoLeft.writeMicroseconds(1700); // SPIN - Left wheel clockwise
    servoRight.writeMicroseconds(1700); // SPIN - Right wheel counterclockwise
    delay(2000);
    servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
    servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal
  }
  else if (pirState == LOW)
  {
    Serial.println("NONE");
    Serial.println(pirState);
    //digitalWrite(pirOutputPin, LOW);
  };
  pirLastState = pirState;
}

