#include <Wire.h>
#include <VL53L0X>
#include "Control_Functions.h"

#define I2CADR 0x11
#define stepPin 4
#define dirPin 5

bool direct = true; //UP is true, down is false
bool climb = false;
bool done = false;
double dist =0;

void setup() {
  wire.begin(I2CADR);
  Control_Functions.setAdrs();
}

void loop() {
  Wire.onReceive(climb = true);
  if(climb){
    while(climb){
      dist = getDist(direct);
      if (dist < 5) placeStack(); 
        
      
    }
  }
}

void placeStack(){
  
}

double getDist(bool direct){
  uint8_t adr;
  if(direct) adr = UPADR;
  else adr = DOWNADR;
  
}
