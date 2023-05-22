#include "gyro.h" //Add library

AcGyro Test(9600); //Create the object and define the velocity

void setup() {

  Test.initMPU(); //Initialize MPU
}

void loop() {
  
 float aX=Test.readAccelerationX(); // acceleration of X
 float aY=Test.readAccelerationY(); // acceleration of y
 float aZ=Test.readAccelerationZ(); // acceleration of z
   Serial.print("Acceleration X: ");    //Print acceleration  X
     Serial.print(aX);
     Serial.print(" Acceleration Y: "); //Print acceleration  y
     Serial.print(aY);
     Serial.print(" Acceleration Z: "); //Print acceleration  z
     Serial.print(aZ);

 float gX=Test.readGyroX(); //Get values from the gyroscope X axis
 float gY=Test.readGyroY(); //Get values from the gyroscope  Y axis
 float gZ=Test.readGyroZ(); //Get values from the gyroscope  Z axis
   Serial.print(" Rotation X: "); //Print values
     Serial.print(gX);
     Serial.print(" Rotation Y: ");
     Serial.print(gY);
     Serial.print(" Rotation Z: ");
     Serial.print(gZ);

 float tem=Test.readTemp(); 
 Serial.print(" Temp: "); 
     Serial.println(tem); 
     
}
