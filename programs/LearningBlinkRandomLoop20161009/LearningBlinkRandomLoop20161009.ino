// set Arduino UNO board
// Port: /dev/tty.usbmodem1411
// Programmer: arduino
// Overriding Baud Rate: 115200

int ledPins[] = {3,6,9};
int randomPin;

// All Arduino sketches MUST have two specific functions, named "setup()" and "loop()". 
// The Arduino runs these functions automatically when it starts up or if you press the reset / button.

// The setup() function runs once when the sketch starts.
// You'll use it for things you need to do first, or only once:

void setup() {
  Serial.begin(9600);

  for (int i=0; i <= 2; i++){
      // initialize digital pin number led as an output.
      // The pinMode() function takes two values, which you type in
      // the parenthesis after the function name. The first value is
      // a pin number, the second value is the word INPUT or OUTPUT.
      pinMode(ledPins[i], OUTPUT);
  } 
  
  randomSeed(analogRead(0));

  Serial.print(ledPins[2]); // turn Serial Monitor on to see output
  Serial.print("SETUP-END\n"); // turn Serial Monitor on to see output
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("LOOP-RUN\n"); // turn Serial Monitor on to see output

  randomPin = random(0,3);
  Serial.print(randomPin);
  Serial.print("\n");

  // The 13 digital pins on your Arduino are great at inputting
  // and outputting on/off, or "digital" signals. These signals
  // will always be either 5 Volts (which we call "HIGH"), or
  // 0 Volts (which we call "LOW").

  // digitalWrite() is the built-in function we use to make an
  // output pin HIGH or LOW. It takes two values; a pin number,
  // followed by the word HIGH or LOW:

  digitalWrite(ledPins[randomPin], 5);   // turn the LED on (5 is the HIGH is the voltage level)
  delay(500);            // wait for a second
  digitalWrite(ledPins[randomPin], 0);   // turn the LED off by making the voltage 0 (or LOW)
  delay(500);

  // reverse the direction of the fading at the ends of the fade: 
  /*
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  */

}
