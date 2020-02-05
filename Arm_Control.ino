#include <Servo.h>


#define Xpin 1
#define Ypin 1
#define Zpin 1
#define Ppin 1
#define Gpin 1

Servo Xserv, Yserv, Zserv, Pserv, Gserv;
float thetaX, thetaY, thetaZ, thetaP, thetaG; // in radians (X is degrees)
float Ytg, Pte, Offx, L;

void attchServos(){
  Xserv.attach(Xpin);
  Yserv.attach(Ypin);
  Zserv.attach(Zpin);
  Pserv.attach(Ppin);
  Gserv.attach(Gpin);
}

void target(float R, float D, float H){
  thetaX = R;
  thetaZ = abs(2*atan(sqrt((-(D*D - 2*D*Offx - 2*D*Pte + H*H - 2*H*Ytg + Offx*Offx + 2*Offx*Pte + Pte*Pte + Ytg*Ytg)/(D*D - 2*D*Offx - 2*D*Pte + H*H - 2*H*Ytg - 4*L*L + Offx*Offx + 2*Offx*Pte + Pte*Pte + Ytg*Ytg)))));
  thetaY = asin(L*thetaZ/sqrt(pow(D-Pte,2)+pow(H-Ytg,2)));
  thetaP = thetaZ+thetaY;
  Xserv.write(thetaX)
  Yserv.write(thetaY*180/M_PI);
  Zserv.write(thetaZ*180/M_PI);
  Pserv.write(thetaP*180/M_PI);
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
