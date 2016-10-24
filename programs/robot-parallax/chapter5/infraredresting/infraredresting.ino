/*
 * Robotics with the BOE Shield - TestLeftIR
 * Display 1 if the left IR detector does not detect an object,
 * or 0 if it does.
 */

void setup() // Built-in initialization block
{

  // Set data rate to 9600 bps
  Serial.begin(9600);                        

  // Play tone for 1 second    
  tone(4, 3000, 100); // move this back to 1000 for duration from 100                       
  
  // Delay to finish tone
  delay(1000);                               

  // left IR receiver input
  pinMode(10, INPUT);
  // left IR LED output
  pinMode(9, OUTPUT);
  
  // right IR receiver input
  pinMode(3, INPUT);
  // right IR LED output
  pinMode(2, OUTPUT);
  
  //pinMode(8, OUTPUT); pinMode(7, OUTPUT);    // Indicator LEDs
  
}  

// Main loop auto-repeats
void loop()
{

  // check for left object
  int irLeft = irDetect(9, 10, 38000);
  Serial.println(irLeft);

  // Display 1/0 no detect/detect
  if (irLeft == 0)
  {
    Serial.println("LEFT");
  }
  else if (irLeft == 1)
  {
    Serial.println("NO-LEFT");
  };

  // check for right object
  int irRight = irDetect(2, 3, 38000);
  Serial.println(irRight);
  
  if (irRight == 0)
  {
    Serial.println("RIGHT");
  }
  else if (irRight == 1)
  {
    Serial.println("NO-RIGHT");
  };

  //digitalWrite(8, !irLeft);                  // LED states opposite of IR   
  //digitalWrite(7, !irRight);

  delay(500); // 0.1 second delay
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

