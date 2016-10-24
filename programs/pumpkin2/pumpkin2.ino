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

const int irLedOutputPin = 2;
const int irReceiverInputPin = 3;
const int outputPinToOtherBoard = 9;

void setup(){
  
  Serial.begin(9600);
  Serial.println("Beep");
  tone(4, 3000, 100);

  // delay to finish tone and wait
  delay(500);

  // IR receiver input
  pinMode(irReceiverInputPin, INPUT);
  // IR LED output
  pinMode(irLedOutputPin, OUTPUT);
  
  // output for LED strip
  pinMode(outputPinToOtherBoard, OUTPUT);
  
  servoLeft.attach(13); // Attach left signal to pin 13
  servoRight.attach(12); // Attach left signal to pin 12

  servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
  servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal
  
  digitalWrite(outputPinToOtherBoard, LOW);
}

void loop(){

  // check for object
  int irObject = irDetect(irLedOutputPin, irReceiverInputPin, 38000);
  Serial.println(irObject);
  digitalWrite(outputPinToOtherBoard, LOW);
  
  if (irObject == 0)
  {
    Serial.println("RIGHT");
  }
  else if (irObject == 1)
  {
    Serial.println("NO-RIGHT");
  };

  if (irObject == 0)
  {
    // spin
    servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
    servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
    
    digitalWrite(outputPinToOtherBoard, HIGH);
    digitalWrite(outputPinToOtherBoard, LOW);
    
    delay(2000);
    
    servoLeft.writeMicroseconds(1500); // 1.5 ms stay-still signal
    servoRight.writeMicroseconds(1500); // 1.5 ms stay-still signal
  
    Serial.println("SPIN");
    tone(4, 3000, 100);
    delay(2000); // 10 second delay
  } 

}

// IR Object Detection Function

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);              // IRLED 38 kHz for at least 1 ms
  delay(1);                                  // Wait 1 ms
  int ir = digitalRead(irReceiverPin);       // IR receiver -> ir variable
  delay(1);                                  // Down time before recheck
  return ir;                                 // Return 1 no detect, 0 detect
}
