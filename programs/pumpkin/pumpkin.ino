/*
set Arduino UNO board for blue
set Arduino Duemilanove w/ ATmega328
Port: /dev/tty.usbmodem1411
Programmer: arduino
Overriding Baud Rate: 115200

spin pumpkin upon sensor sensing

*/

// libraries
#include <Servo.h> // Include servo library

Servo servoLeft;  // Declare left servo
Servo servoRight;  // Declare right servo

void setup(){
  
  Serial.begin(9600);
  Serial.println("Beep");
  tone(4, 3000, 1000);
  
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach left signal to pin 12

  delay(3000);
  
  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal

  Serial.println("1\n");

  delay(3000);
  
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(400);
  
  delay(3000);
  
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);

  Serial.println("2\n");
  
  delay(3000);

  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);

  delay(3000);
  
  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal

  Serial.println("3\n");
  
  
}

void loop(){

}
