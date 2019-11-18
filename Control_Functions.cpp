double PID(PIDdata *dat, double currValue, int dt){
  double error = currValue - dat->goal;
  dat->intError += error * dt;
  
  return (dat->KP * error + dat->KI * dat->intError + dat->KD * (error - dat->prevError)/ dt);
}


