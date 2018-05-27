#define FG 13
  // Pin 13: Arduino has a function generator connected on pin 13
#define LED 8
  //Arduino has an LED PIN connected to pin8

void setup() {
  // initialize PIN13 as an output:
  pinMode(FG, OUTPUT); 
  // initialize PIN8 as an output
  pinMode(LED,OUTPUT); 
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop(){
  // Simulate mouse action by sending LED, FG HIGH

  delay(random(20, 3000));
  digitalWrite(FG, HIGH);
  digitalWrite(LED, HIGH);
  delay(random(10, 20));
  digitalWrite(FG, LOW); 
  digitalWrite(LED, LOW);
}
