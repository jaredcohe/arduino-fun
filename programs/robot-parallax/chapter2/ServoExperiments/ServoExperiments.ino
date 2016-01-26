/*
 Robotics with the BOE Shield – LeftServoStayStill
 Generate signal to make the servo stay still for centering.
 http://learn.parallax.com/node/186
*/

#include <Servo.h> // Include servo library

Servo servoLeft;  // Declare left servo
Servo servoRight;  // Declare right servo

void setup(){
  
  Serial.begin(9600);
  Serial.println("Beep");
  tone(4, 3000, 1000);
  delay(1000);
  
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach left signal to pin 12

  //servoLeft.writeMicroseconds(1300); // 1.3 ms top RPM clockwise
  //servoRight.writeMicroseconds(1700); // 1.7 ms top RPM counterclockwise

  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);

  delay(2000);

  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);

  delay(2000);

  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);

  delay(2000);

  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);

  delay(2000);

  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal

  servoLeft.detach(); // stop servo signal to pin 13
  servoRight.detach(); // stop servo signal to pin 12

}

void loop(){

  Serial.println("Waiting for reset...");
  delay(1000);

}

