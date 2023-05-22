
#ifndef OBSTACLECLASS_H
#define OBSTACLECLASS_H

#include <Arduino.h>
#include "motorClass.h"
#include <Servo.h>

class obstacleClass {
private:
  int trigPin;             // Pin for the ultrasonic sensor trigger
  int echoPin;             // Pin for the ultrasonic sensor echo
  int servo;               // Pin for the servo motor
  float duration;          // Duration of the ultrasonic pulse
  float distance;          // Calculated distance from the ultrasonic sensor
  int activated;           // Status of obstacle mode activation
  motorClass obstacleCar;  // Instance of the motorClass for the obstacle car
  Servo myservo;           // Servo motor instance

public:
  obstacleClass(){};
  obstacleClass(int multiPins[]);

  void init();
  void read();
  void changeMotors(int multiPins[]);
  void obstacleMove();
  void obstacleStop();
};

#endif
