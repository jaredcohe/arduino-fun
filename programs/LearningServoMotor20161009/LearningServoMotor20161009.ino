#include <Servo.h>

Servo servo1;  // servo control object

void setup()
{
  Serial.begin(9600);
  servo1.attach(9); 
}


void loop()
{
  servo1.write(10);    // Tell servo to go to 90 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(20);   // Tell servo to go to 180 degrees
}

