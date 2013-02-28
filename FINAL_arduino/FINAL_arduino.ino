#include <Servo.h>

//Declare servo objects
Servo servoA;
Servo servoB;

//Declare all pin variables
int potPin = 0;
int photoResPin = 1;
int buttonPin = 2;
int servoApin = 3;
int servoBpin = 4;
int LEDaPin = 5;
int LEDbPin = 6;

//Create two variables for storing readings
int valA;
int valB;


void setup() {
  //Connect the two servos
  servoA.attach(servoApin);
  servoB.attach(servoBpin);
  
  //Set digital pins to the appropriate mode
  pinMode(buttonPin, INPUT);
  pinMode(LEDaPin, OUTPUT);
  pinMode(LEDbPin, OUTPUT);
  
  //Open serial communication for remote control
  Serial.begin(9600);
}


void loop() {  
  //Check if there is a serial connection
  if (Serial.available() > 0) {
    //Make sure the serial data is the value we want
    if (Serial.read() == 1) {
      //Now we can do a sequence of cool things!!
      digitalWrite(LEDaPin, HIGH);
      delay(500);
      digitalWrite(LEDaPin, LOW);
    }
  }
  
  //Get readings from potentiometer and photoresistor
  valA = analogRead(potPin);
  valB = analogRead(photoResPin);
  
  //Map vals from range of 0-1023 to range to 1-180
  valA = map(valA, 0, 1023, 0, 180);
  valB = map(valB, 0, 1023, 0, 180);
  
  //Check if the button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    //Switch which LED is lit
    digitalWrite(LEDaPin, HIGH);
    digitalWrite(LEDbPin, LOW);
    
    //Set servos with vals
    servoA.write(valA);
    servoB.write(valB);
    
  } else {
    //Switch which LED is lit
    digitalWrite(LEDaPin, LOW);
    digitalWrite(LEDbPin, HIGH);
    
    //Set servos with vals
    servoA.write(valB);
    servoB.write(valA);
  }
}
