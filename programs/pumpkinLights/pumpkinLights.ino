/*
 http://www.arduino.cc/en/Tutorial/Button
 */

// set pin numbers:
const int inputFromOtherBoard = 4;
//const int ledPin =  13;      // the number of the LED pin

// variables will change:
int inputState = 0;         // variable for reading the pushbutton status

void setup() {
  
  Serial.begin(9600);
  Serial.println("STARTING-LIGHTS-BOARD");

  // initialize the LED pin as an output:
  //pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(inputFromOtherBoard, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  inputState = digitalRead(inputFromOtherBoard);
  Serial.println("INPUT-STATE:");
  Serial.println(inputState);

  /*
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (inputState == HIGH) {     
    // turn  on:    
    digitalWrite(ledPin, HIGH);
    delay(2000);
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  */
}
