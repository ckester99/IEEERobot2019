#include <Servo.h>


#define Xpin 3
#define Ypin 5
#define Zpin 6
#define Ppin 9
#define Gpin 10

Servo Xserv, Yserv, Zserv, Pserv, Gserv;
float thetaX, thetaY, thetaZ, thetaP, thetaG; // in radians (X is degrees)
float Ytg, Pte, Offx, L;

void setConstants(){
  L = 9.26;
  Ytg = .89;
  Offx = .54;
  Pte = 0;
}

void attchServos(){
  Xserv.attach(Xpin);
  Yserv.attach(Ypin);
  Zserv.attach(Zpin);
  Pserv.attach(Ppin);
  Gserv.attach(Gpin);
}

void target(float R, float D, float H){
  thetaX = R;
  float d = D - Pte + Offx;
  float h = H - Ytg;
  psiY = atan(h/d);
  thetaZ = acos(1-(d*d + h*h)/(2*L*L));
  phiY = asin(L*sin(thetaZ)/sqrt(d*d+h*h));
  thetaY = phiY+psiY;
  thetaP = thetaY + thetaZ;

  Xserv.write(R);
  Yserv.write(thetaY*180/M_PI);
  Zserv.write(thetaZ*180/M_PI);
  Pserv.write(thetaP*180/M_PI);
}
