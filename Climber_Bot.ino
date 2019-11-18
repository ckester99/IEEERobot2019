#include <Wire.h>
#include <VL53L0X>
#include "Control_Functions.h"

#define I2CADR 0x11
#define TOFUADR 0x29
#define TOFDADR 0x30
#define ENPINTOFU 7
#define ENPINTOFD 8
#define RECPIN 10
#define SENDPIN 11


bool direct = true; //UP is true, down is false
bool climb = false;
bool done = false;
double dist =0;
VL53L0X TOFU;
VL53L0X TOFD;

void setup() {
  Serial.begin(9600);
  setupTOF();
  pinMode(RECPIN,INPUT);
  pinMode(SENDPIN,OUTPUT);//will send 1 when ready to recieve blocks
}

void loop() {
  climb = digitalRead(RECPIN); //1 sends monkey up tower
  if (climb){
    while(!done){
    
    }  
  } 
  done = false;
}

void placeStack(){
  
}

void setupTOF(){
  pinMode(ENPINTOFU,OUTPUT);
  pinMode(ENPINTOFD,OUTPUT);
  digitalWrite(ENPINTOFU,HIGH);
  digitalWrite(ENPINTOFD,LOW);
  TOFU.setTimeout(500);
  if (!TOFU.init())
  {
    Serial.println("Failed to detect and initialize TOFU!");
    while (1) {}
  }
  TOFU.setAddress(TOFUADR);
  digitalWrite(ENPINTOFU,LOW);
  digitalWrite(ENPINTOFD,HIGH);
  TOFD.setTimeout(500);
  if (!TOFD.init())
  {
    Serial.println("Failed to detect and initialize TOFD!");
    while (1) {}
  }
  TOFD.setAddress(TOFDADR);
  digitalWrite(ENPINTOFU,HIGH);
  
}  

uint16_t getDist(bool direct){
  uint16_t val;
  if(direct) val = TOFU.readRangeSingleMillimeters();
  else val = TOFD.readRangeSingleMillimeters();
  return val;
}
