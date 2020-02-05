struct stepperData{
  unsigned long lastStepTime; //microseconds
  float rpm, stepToInch;
  int currStep, targetStep, driveMode, fullStepPerRev;
  const int dirPin;
  uint8_t *port, mask; //pointer to port step pin is on and bitmask to set pin high
  bool on;
};

void stepper(stepperData *dat, unsigned long currTime){
  //driveMode 1 = continuous rotation at RPM
  if ((dat->driveMode == 1) && (30000000/(dat->rpm * dat->fullStepPerRev)) ){ //60*10^6 / (rpm*stepsPerRev*2)
    if(dat->on) {
      *(dat->port) &= ~dat->mask;
      dat->lastStepTime = micros();
      dat->on = false;
    }
    else {
      *(dat->port) |= dat->mask;
      dat->lastStepTime = micros();
      dat->on = true;
    }
  }
  //driveMode 2 = move to a target step number at RPM
  if ((dat->driveMode == 2) && (30000000/(dat->rpm * dat->fullStepPerRev)) && (dat->currStep != dat -> targetStep) ){ //60*10^6 / (rpm*stepsPerRev*2)
    if(dat->targetStep != dat->currStep){
      if(dat->targetStep > dat->currStep){
        digitalWrite(dat->dirPin,HIGH);
        dat->currStep++;
      }
      else{
        digitalWrite(dat->dirPin,LOW);
        dat->currStep--;
      }
      if(dat->on) {
        *(dat->port) &= ~dat->mask;
        dat->lastStepTime = micros();
        dat->on = false;
      }
      else {
        *(dat->port) |= dat->mask;
        dat->lastStepTime = micros();
        dat->on = true;
      }
    }
  }
  
}

void setup(){

  
}

void loop(){
  
}
