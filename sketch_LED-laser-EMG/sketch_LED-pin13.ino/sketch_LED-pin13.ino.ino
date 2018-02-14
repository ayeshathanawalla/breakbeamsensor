#define FG 13
  // Pin 13: Arduino has a function generator connected on pin 13
#define LED 8
  //Arduino has an LED PIN connected to pin8
#define SENSORPIN 4
  //IR breakbeam sensor input


// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup() {
  // initialize PIN13 as an output:
  pinMode(FG, OUTPUT); 
  // initialize PIN8 as an output
  pinMode(LED,OUTPUT); 
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn FG on,turn EMG on, Turn LED on, turn counter on:
    digitalWrite(FG, HIGH);
    digitalWrite(LED, HIGH); 
  } 
  else {
    // turn FG off:
    digitalWrite(FG, LOW); 
    digitalWrite(LED, LOW);
   
  }

  lastState = sensorState;
}
