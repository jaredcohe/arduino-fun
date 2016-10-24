// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define GREENPIN 8
#define REDPIN 9
 
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
}
 
 
void loop() {
  int r, g;
 
  // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPIN, r);
    delay(10);
  }
  for (g = 0; g < 256; g++) { 
    analogWrite(GREENPIN, g);
    delay(10);
  } 
}
