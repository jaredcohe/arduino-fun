/*
    Robotics with the BOE Shield – TestServoSpeed
 Send a character from the Serial Monitor to the Arduino to make it run the
 left servo for 6 seconds. Starts with 1375 us pulses and increases by
 25 us with each repetition, up to 1625 us. This sketch is useful for
 graphing speed vs. pulse width.
    http://learn.parallax.com/node/208
*/

#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup()
{
  tone(4, 3000, 1000);
  delay(1000);

  Serial.begin(9600);
  servoLeft.attach(13);
}

void loop()
{
  // Loop counts with pulseWidth from 1375 to 1625 in increments of 25.
  for(int pulseWidth = 1375; pulseWidth <= 1625; pulseWidth += 25)
  {
    Serial.print("pulseWidth = ");
    Serial.println(pulseWidth);
    Serial.println("Press a key and click");
    Serial.println("Send to start servo...");

    Serial.println(Serial.available());

    /*
     * The C language allows the while loop to use an 
     * empty code block, in this case to wait there until 
     * it receives a character.  When you type a character 
     * into the Serial Monitor, Serial.available returns 1 
     * instead of 0, so the while loop lets the sketch move 
     * on to the next statement.
     */
    while(Serial.available() == 0); //wait for character
    
    Serial.println(Serial.available());
    char x = Serial.read(); // clears character
    Serial.println(x);
    Serial.println(Serial.available());

    Serial.println("Running...");
    servoLeft.writeMicroseconds(pulseWidth); // pin 13 servo speed = pulse
    delay(6000);
    servoLeft.writeMicroseconds(1500); // pin 13 servo speed = stop
  }
}

