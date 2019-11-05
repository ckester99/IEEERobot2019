double PID(PIDdata *dat, double currValue){
  double error = currValue - *dat.goal;
  *dat.intError += error * *dat.DT;
  
  return (*dat.KP * error + *dat.KI * *dat.intError + *dat.KD * (error - *dat.prevError)/ *dat.DT);
}
