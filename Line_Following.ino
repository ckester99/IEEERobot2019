#define lLightPin 1
#define rLightPin 1
#define WHITE_TOL 900
#define DEB_TIME 25000 //in microseconds

float RPM;
unsigned long debWhite, debBlack, lastTime;
int pos, lLight,rLight, travelDir;
bool onWhite,changePosFlag;

void followLine(unsigned long currTime){
  lLight = analogRead(lLightPin);
  rLight = analogRead(rLightPin);
  unsigned long dt = currTime-lastTime;
  
  if ( lLight > WHITE_TOL && rLight > WHITE_TOL){//drive straight
    debWhite += dt;
    debBlack =0;
  }

  if ( lLight < WHITE_TOL && rLight < WHITE_TOL){//drive straight
    debWhite = 0;
    debBlack += dt;
  }

  if ( lLight > WHITE_TOL && rLight < WHITE_TOL){//turn left
    
  }

  if ( lLight < WHITE_TOL && rLight > WHITE_TOL){//turn right
    
  }  

  if (debWhite >= DEB_TIME){
    onWhite = true;
    changePosFlag = true;
  }
  else if(!onWhite && changePosFlag){
    pos += travelDir;
    changePosFlag = false;
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
