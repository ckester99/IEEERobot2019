#include <Wire.h>
#include <VL53L0X>
#include "Control_Functions.h"

#define I2CADR 0x11
#define TOFUADR 0x29
#define TOFDADR 0x30
#define ENPINTOFU 7
#define ENPINTOFD 8
#define stepPin 4
#define dirPin 5

bool direct = true; //UP is true, down is false
bool climb = false;
bool done = false;
double dist =0;

void setup() {
  wire.begin(I2CADR);
  Control_Functions.setAdrs(TOFUADR,ENPINTOFU,TOFDADR,ENPINTOFD);
  Stepper climber;
  Stepper placer;
}

void loop() {
  Wire.onReceive(climb = true);
  while(climb){
    
  }  
}

void placeStack(){
  
}

double getDist(bool direct){
  uint8_t adr;
  if(direct) adr = UPADR;
  else adr = DOWNADR;
  
}
