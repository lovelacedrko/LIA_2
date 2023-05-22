#include "obstacleClass.h"

obstacleClass::obstacleClass(int multiPins[]) {
  trigPin = multiPins[0];     // Assign the trigger pin for the ultrasonic sensor
  echoPin = multiPins[1];     // Assign the echo pin for the ultrasonic sensor
  servo = multiPins[2];       // Assign the pin for the servo motor
  activated = 0;              // Initialize the activation status
  obstacleCar.init();         // Initialize the obstacle car
  obstacleCar.setSpeed(255);  // Set the speed of the obstacle car
}

void obstacleClass::init() {
  pinMode(trigPin, OUTPUT);  // Set the trigger pin as output
  pinMode(echoPin, INPUT);   // Set the echo pin as input
  myservo.attach(servo);     // Attach the servo motor to the pin
}

void obstacleClass::read() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);   // Measure the duration of the pulse
  distance = (duration / 2) * 0.0343;  // Calculate the distance based on the duration
}

void obstacleClass::changeMotors(int multiPins[]) {
  obstacleCar.changeMotors(multiPins);  // Change the motor pin configuration
}

void obstacleClass::obstacleMove() {
  obstacleCar.move(1, 128, 1, 128);  // Move the obstacle car forward
  myservo.write(90);                 // Set the servo to the center position
  read();                            // Read the distance from the ultrasonic sensor

  if (activated == 1) {
    if (distance <= 100) {
      obstacleCar.move(0, 0, 0, 0);  // Stop the obstacle car
      myservo.write(180);            // Rotate the servo to the right
      delay(750);
      read();
      myservo.write(90);  // Set the servo to the center position

      if (distance <= 30) {
        obstacleCar.move(0, 0, 0, 0);  // Stop the obstacle car
        myservo.write(0);              // Rotate the servo to the left
        delay(750);
        read();
        myservo.write(90);  // Set the servo to the center position

        if (distance <= 30) {
          obstacleCar.move(1, 255 / 3, 0, 255 / 3);  // Move diagonally forward-left
          delay(1500);
          return;

        } else {
          obstacleCar.move(0, 255 / 3, 1, 255 / 3);  // Move diagonally forward-right
          delay(750);
          return;
        }

      } else {
        obstacleCar.move(1, 255 / 3, 0, 255 / 3);  // Move diagonally forward-left
        delay(750);
        return;
      }
    }
  } else {
    return;
  }
}

void obstacleClass::obstacleStop() {
  activated = 0;  // Deactivate the obstacle mode
}
