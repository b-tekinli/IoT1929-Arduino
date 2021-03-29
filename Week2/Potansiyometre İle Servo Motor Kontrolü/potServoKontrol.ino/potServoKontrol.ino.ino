#include <Servo.h>

Servo servoMotor;
int pin = A0;
int buttonPin = 5;
int value = 0;


void setup(){
  pinMode(buttonPin, INPUT);
  servoMotor.attach(11);
  }

void loop(){
  if (digitalRead(buttonPin) == HIGH){
    value = analogRead(pin);
    value = map(value, 0, 1023, 0, 180);  // 180 derece hareket ettiriyoruz.
    servoMotor.write(value);
    delay(2000);
  }
  else if(digitalRead(buttonPin) == LOW){
    value = analogRead(pin);
    value = map(value, 0, 1023, 0, 90);   // 90 derece hareket ettiriyoruz.
    servoMotor.write(value);
    delay(2000);
  }
}
