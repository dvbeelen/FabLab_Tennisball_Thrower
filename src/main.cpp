#include <Arduino.h>
#include <Ultrasonic.h>
#include <Servo.h>
//Define pins

Servo katapultServo;
Ultrasonic ultrasonic(9, 10);


void setup() {
  Serial.begin(9600);
  katapultServo.attach(8);
}

void loop() {
  int distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
  Serial.println(distance);
  delay(1000);

  if (distance < 50 ) {
    katapultServo.write(10);
    delay(1000);
  } 
  else {
    katapultServo.write(180);
    delay(1000);
  }
}