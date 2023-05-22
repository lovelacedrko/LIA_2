#ifndef LINETRACKERCLASS_H
#define LINETRACKERCLASS_H

#include <Arduino.h>     // Include the Arduino library
#include "motorClass.h"  // Include the "motorClass.h" header file

class lineClass {
private:
  int rightPin;
  int middlePin;
  int leftPin;
  int right;
  int middle;
  int left;
  int motorPins;
  int activated;
  motorClass lineCar;

public:
  linetrackerClass(){};               // Default constructor
  lineClass(int multiPins[]);  // Constructor with multiPins array as a parameter

  void linetracker();                    // Track the line and read sensor values
  void lineMove();                     // Move the line based on sensor values
  void changeMotors(int multiPins[]);  // Change the motors used by lineCar
  void whatTrack();                    // Print sensor values for debugging
  void lineStop();                     // Stop line tracking
};

#endif
