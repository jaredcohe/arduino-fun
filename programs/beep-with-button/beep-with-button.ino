
int led = 10;
int beep = 13;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(beep, OUTPUT);
}

void loop(){

  tone(beep, 3000, 1000);
  digitalWrite(led, 5);
  delay(3000);

}

