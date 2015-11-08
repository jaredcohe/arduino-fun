// set Arduino UNO board
// Port: /dev/tty.usbmodem1411
// Programmer: arduino
// Overriding Baud Rate: 115200

// wire: GND to - column
// resistor: - column to a3
// led: c3 to c2 (short/negative in c3)
// wire: e2 to pin12


int led = 12;         // the pin that the LED is attached to
//int brightness = 0;   // how bright the LED is
//int fadeAmount = 5;   // how many points to fade the LED by

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  // initialize digital pin number led as an output.
  pinMode(led, OUTPUT);
  Serial.print("8"); // turn Serial Monitor on to see output
}

// the loop function runs over and over again forever
void loop() {
  //Serial.print("test"); // turn Serial Monitor on to see output

  digitalWrite(led, 5);   // turn the LED on (5 is the HIGH is the voltage level)
  delay(100);            // wait for a second
  digitalWrite(led, 0);   // turn the LED off by making the voltage 0 (or LOW)
  delay(100);            // wait
  Serial.print("OnOff\n"); // turn Serial Monitor on to see output


  // reverse the direction of the fading at the ends of the fade: 
  /*
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  */

}
