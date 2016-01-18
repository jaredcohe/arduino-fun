/*
 Robotics with the BOE Shield – LeftServoStayStill
 Generate signal to make the servo stay still for centering.
 http://learn.parallax.com/node/179
*/

#include <Servo.h> // Include servo library

Servo servoLeft;  // Declare left servo
Servo servoRight;  // Declare right servo

void setup(){
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach left signal to pin 12

  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal

}

void loop(){

}
