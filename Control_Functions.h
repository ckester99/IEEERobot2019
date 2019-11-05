# ifndef CONTROL_FUNCTIONS_H
#define CONTROLS_FUNCTIONS_H

typedef struct vals{
  float KP;
  float KI;
  float KD;
  uint16_t DT;
  double goal;
  
  double prevError;
  unsigned long prevTime
  long double intError;  
} PIDdata;

double PID(PiDdata *dat,double currValue);

#endif
