/*
 Robotics with the BOE Shield – LeftServoStayStill
 Generate signal to make the servo stay still for centering.
 http://learn.parallax.com/node/179
*/

#include <Servo.h> // Include servo library

Servo servoLeft;  // Declare left servo

void setup(){
  servoLeft.attach(13); // Attach left signal to pin 13
  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
}

void loop(){

}
