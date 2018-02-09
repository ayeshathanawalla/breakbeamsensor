
#define FG 13
  // Pin 13: Arduino has a function generator connected on pin 13
  
#define SENSORPIN 4

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup() {
  // initialize the BNC as an output:
  pinMode(FG, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn FG on:
    digitalWrite(FG, HIGH);  
  } 
  else {
    // turn FG off:
    digitalWrite(FG, LOW); 
  }
 
  lastState = sensorState;
}
