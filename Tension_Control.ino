#include <MPU6050_tockn.h>
#include <Wire.h>
#include "Control_Functions.h"

#define KP 1
#define KI 1
#define KD 1
#define DT 50 //milliseconds

PIDdata ctrR; //[sqrt(3)/2,-1/2,0]
PIDdata ctrL; //[-sqrt(3)/2,-1/2,0]

double datR, datL;
MPU6050_tockn sense;
double aX,aY,aZ;

void setup() {
  Wire.begin();
  
  ctrL.KP = KP; ctrR.KP = KP;
  ctrL.KI = KI; ctrR.KI = KI;
  ctrL.KD = KD; ctrR.KD = KD;
  ctrL.DT = DT; ctrR.DT = DT;
  ctrL.goal = 0; ctrR.goal =0;
  
}

void loop() {
  sens.update();
  aX = sense.getAngleX(); aY = sense.getAngleY(); z = sense.getAngleZ();
  aL = sqrt(aX*aX + aY*aY+ aZ*aZ);
  
  datR = (aX*-sqrt(3)/2+aY()*1/2)/aL;
  datL = (aX*sqrt(3)/2+aY()*-1/2)/aL;
  
  PID(&ctrR,datR);
  PID(&ctrL,datL);

}
