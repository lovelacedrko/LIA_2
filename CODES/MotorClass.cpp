#include "motorClass.h"

motorClass::motorClass(int multiPins[]) {
  PWMA = multiPins[0];  // Assign the value of multiPins[0] to PWMA
  PWMB = multiPins[1];  // Assign the value of multiPins[1] to PWMB
  AIN1 = multiPins[2];  // Assign the value of multiPins[2] to AIN1
  BIN1 = multiPins[3];  // Assign the value of multiPins[3] to BIN1
}

void motorClass::init() {
  pinMode(PWMA, OUTPUT);  // Set PWMA pin as an output
  pinMode(PWMB, OUTPUT);  // Set PWMB pin as an output
  pinMode(AIN1, OUTPUT);  // Set AIN1 pin as an output
  pinMode(BIN1, OUTPUT);  // Set BIN1 pin as an output
  pinMode(3, OUTPUT);     // Set pin 3 as an output
  digitalWrite(3, 1);     // Set pin 3 to high (assumed enable pin)
}

void motorClass::changeMotors(int multiPins[]) {
  PWMA = multiPins[0];  // Assign the value of multiPins[0] to PWMA
  PWMB = multiPins[1];  // Assign the value of multiPins[1] to PWMB
  AIN1 = multiPins[2];  // Assign the value of multiPins[2] to AIN1
  BIN1 = multiPins[3];  // Assign the value of multiPins[3] to BIN1
}

void motorClass::move(bool a, int x, bool b, int y) {
  digitalWrite(AIN1, a);  // Set AIN1 pin based on the value of 'a'
  analogWrite(PWMA, x);   // Set PWMA pin to the value of 'x' (PWM signal)
  digitalWrite(BIN1, b);  // Set BIN1 pin based on the value of 'b'
  analogWrite(PWMB, y);   // Set PWMB pin to the value of 'y' (PWM signal)
}

void motorClass::setSpeed(int speed) {
  this->speed = speed;  // Set the value of 'speed' using the provided argument
}

void motorClass::forward(int x) {
  move(1, speed / 2, 1, speed / 2);  // Move the motors forward using speed/2 as the PWM values
}

void motorClass::backward(int x) {
  move(0, speed / 2, 0, speed / 2);  // Move the motors backward using speed/2 
}

void motorClass::left(int x) {
  move(1, speed / 3, 0, speed / 3);  // Turn the motors left using speed/3 
}

void motorClass::right(int x) {
  move(0, speed / 3, 1, speed / 3);  // Turn the motors right using speed/3 
}

void motorClass::forwardLeft(int x) {
  move(1, speed / 2, 1, speed / 4);  // Move diagonally forward-left 
}

void motorClass::forwardRight(int x) {
  move(1, speed / 4, 1, speed / 2);  // Move diagonally forward-right 
}

void motorClass::backwardLeft(int x) {
  move(0, speed / 2, 0, speed / 4);  // Move diagonally backward-left 
}

void motorClass::backwardRight(int x) {
  move(0, speed / 4, 0, speed / 2);  // Move diagonally backward-right
}

void motorClass::stop() {
  move(0, 0, 0, 0);  // Stop the motors by setting all PWM values to 0
}
