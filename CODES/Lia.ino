#include "motorClass.h"  // Include motorClass header file
int motors[] = { 5, 6, 7, 8 };
motorClass robotCar(motors);  // Create an instance of motorClass

#include <irremote.h>  // Include IRremote library
int receiver = 9;
IRrecv irrecv(receiver);
decode_results results;

#include "linetrackerClass.h"  // Include lineClass header file
int lines[] = { A0, A1, A2 };
lineClass lineTrack(lines);  // Create an instance of lineClass

#include "obstacleClass.h"  // Include obstacleClass header file
int obstaclePins[] = { 13, 12, 10 };
obstacleClass obstacleAvoid(obstaclePins);  // Create an instance of obstacleClass

#include <Servo.h>  // Include Servo library
Servo ultrasonicServo;
Servo stickServo;  // create servo object to control a servo
Servo myservo1;    // create servo object to control a servo

/*
#include "gyroscope.h"
gyroscopeClass Gyroscope(1);
*/

int mode = 1;
int speed;

void setup() {
  
  Serial.begin(9600);

  robotCar.init();

  irrecv.enableIRIn();

  lineTrack.changeMotors(motors);

  obstacleAvoid.init();
  obstacleAvoid.changeMotors(motors);

  stickServo.attach(10); // Attaches ultrasonic servo to pin 10
  myservo1.attach(11);  // Attaches extra servo to pin 11
  //Gyroscope.init();
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume();

    switch (results.value) {
      case 16730805:               // Button 1 MANUAL MODE
        robotCar.setSpeed(100);  // Set the speed to 100 in default mode
        robotCar.stop();
        lineTrack.lineStop();
        obstacleAvoid.obstacleStop();
        mode = 1;
        break;

      case 16714485:  // Button 2 LINE MODE
        mode = 2;
        break;

      case 16713975:  // Button 3 OBSTACLE MODE
        mode = 3;
        break;

      case 16736415:  // MANUAL FORWARD
        if (mode == 1) {
          mode = 1;
          robotCar.forward(100);
        }
        break;

      case 16734885:  // MANUAL LEFT
        if (mode == 1) {
          mode = 1;
          robotCar.left(100);
        }
        break;

      case 16767015:  // MANUAL RIGHT
        if (mode == 1) {
          mode = 1;
          robotCar.right(100);
        }
        break;

      case 16738455:  // MANUAL BACKWARD
        if (mode == 1) {
          mode = 1;
          robotCar.backward(100);
        }
        break;

      case 16756815:  // Boost Forward home button pressed
        if (mode == 1) {
          mode = 1;
          robotCar.forward(255);
        }
        break;

      case 16730295:  // Servo Left
        if (mode == 1) {
          mode = 1;
          myservo1.write(0);  // Servo writes zero degrees
        }
        break;
      case 16753245:  // Servo Right
        if (mode == 1) {
          mode = 1;
          myservo1.write(180);  // Servo writes 180 degrees
        }
        break;

      case 16752735:  // STOP
        robotCar.stop();
        lineTrack.lineStop();
        obstacleAvoid.obstacleStop();
        break;
    }
  }

  if (mode == 2) {
    lineTrack.lineMove();
    obstacleAvoid.obstacleStop();

  } else if (mode == 3) {
    obstacleAvoid.obstacleMove();
    lineTrack.lineStop();
  }

  //gyroscope.begin();
}
