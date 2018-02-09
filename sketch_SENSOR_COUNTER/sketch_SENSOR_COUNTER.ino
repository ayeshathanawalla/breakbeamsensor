//modified sensor to counter code
// modified for I2C LCD
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

int count=1;
#define SENSORPIN 4
#define LED 13
  //IR breakbeam sensor input

  // variables will change:
int sensorState = 0, lastState=0; 

void setup()
{
  lcd.begin (16,2); //  
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  pinMode(LED, OUTPUT);
  pinMode(SENSORPIN, INPUT); 
  digitalWrite(SENSORPIN,HIGH);  //Turn on pullup  

}

void loop()
{
 // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  
if (sensorState == LOW && lastState == HIGH){
  digitalWrite(LED,HIGH);
  lcd.setCursor(0,0);
  lcd.print(count++);
}

else
{
  digitalWrite(LED,LOW);
}
  lastState = sensorState;
}
