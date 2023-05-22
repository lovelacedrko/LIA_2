#include "LinetrackerClass.h"  // Include the "LinetrackerClass.h" header file

Linetracker::LinetrackerClass(int multiPins[]) {
  // Constructor that takes an array of multiPins as a parameter
  rightPin = multiPins[0];
  middlePin = multiPins[1];
  leftPin = multiPins[2];
  right = 0;
  middle = 0;
  left = 0;
  activated = 0;
  lineCar.init();
  lineCar.setSpeed(255);
}

void LinetrackerClass::lineTrack() {
  // Read the sensor values for rightPin, middlePin, and leftPin
  right = analogRead(rightPin);
  middle = analogRead(middlePin);
  left = analogRead(leftPin);
}

void LinetrackerClass::lineMove() {
  // Activate line tracking mode
  activated = 1;

  // Read the sensor values for rightPin, middlePin, and leftPin
  right = analogRead(rightPin);
  middle = analogRead(middlePin);
  left = analogRead(leftPin);

  // Line following logic based on sensor values
  if (activated == 1) {
    if (right > 40) {
      lineCar.move(0, 43, 1, 43);
    } else if (middle > 40) {
      lineCar.move(1, 85, 1, 85);
    } else if (left > 40) {
      lineCar.move(1, 43, 0, 43);
    } else {
      lineCar.move(1, 85, 0, 85);

      if (middle > 40) {
        return;
      }
    }
  } else {
    lineCar.stop();
    return;
  }
}

void LinetrackerClass::changeMotors(int multiPins[]) {
  // Change the motors of lineCar
  lineCar.changeMotors(multiPins);
}

void LinetrackerClass::whatTrack() {
  // Print the sensor values for debugging purposes
  Serial.print("Right = ");
  Serial.println(right);
  Serial.print("Middle = ");
  Serial.println(middle);
  Serial.print("Left = ");
  Serial.println(left);
}

void LinetrackerClass::lineStop() {
  // Deactivate line tracking mode
  activated = 0;
}
