#include <avr/pgmspace.h>
#include <Servo.h>

#define BUTTONFASTTOLERANCE .01*1000000//time between press of different buttons
#define BUTTONSLOWTOLERANCE .025*1000000//button debounce time
#define DRIVETIME 2 * 1000//time to drive up to wall in ms
#define SERVOTRAVELTIME 2* 1000 //time for servos to deploy arms in ms



unsigned long onTimes[10], offTimes[10];
uint8_t setArr[] = {B00000100,B00001000,B00010000,B00100000,B01000000,B10000000,B00000001,B00000010,B00010000,B00100000};
uint8_t resArr[] = {B11111011,B11110111,B11101111,B11011111,B10111111,B01111111,B11111110,B11111101,B11101111,B11011111};
uint8_t *outReg[] = {&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTB,&PORTB,&PORTB,&PORTB};
unsigned long timeLastPressMicros, dummyTime;
unsigned int currDigit = 3;
int currIndex = 0;

Servo rightServ; //from looking at front of robot
Servo leftServ;

void setup() {
  pinMode(2,OUTPUT);  //DIGIT 0
  pinMode(3,OUTPUT);  //DIGIT 1
  pinMode(4,OUTPUT);  //DIGIT 2
  pinMode(5,OUTPUT);  //DIGIT 3
  pinMode(6,OUTPUT);  //DIGIT 4
  pinMode(7,OUTPUT);  //DIGIT 5
  pinMode(8,OUTPUT);  //DIGIT 6
  pinMode(9,OUTPUT);  //DIGIT 7
  pinMode(12,OUTPUT); //DIGIT 8
  pinMode(13,OUTPUT); //DIGIT 9

  pinMode(A0,OUTPUT); //Motors
  pinMode(A1,OUTPUT);

  rightServ.attach(11);
  leftServ.attach(10);
  rightServ.write(90); //vertical positions
  delay(SERVOTRAVELTIME);
  leftServ.write(90);
  

  digitalWrite(A0,HIGH); //drive forward
  digitalWrite(A1,HIGH);
  delay(DRIVETIME);
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);

  rightServ.write(180);
  leftServ.write(0);
  delay(SERVOTRAVELTIME);
  rightServ.detach();
  leftServ.detach();
  
  
  for (int i = 0;i<10;i++){
    onTimes[i] = 1;
    offTimes[i] = 1;
  }

  
  

  
}

/*  TESTING CODE/ BACKUP PLAN
int k = 0;
char myChar;
void loop(){
  dummyTime = micros();
  if(dummyTime - timeLastPressMicros > BUTTONSLOWTOLERANCE){
    myChar = pgm_read_byte_near(pi + k++);
    //Serial.print(myChar);

    currDigit = myChar - '0';
    *outReg[currDigit] |= setArr[currDigit];
    timeLastPressMicros = micros();
    delay(BUTTONSLOWTOLERANCE/1000);
    *outReg[currDigit] &= resArr[currDigit];
 
  }
  
}
*/

void loop(){ //button pushing
  
 
  
  dummyTime = micros();
  if(dummyTime - offTimes[currDigit] > BUTTONSLOWTOLERANCE  &&  dummyTime - timeLastPressMicros > BUTTONFASTTOLERANCE && offTimes[currDigit] != 0){
    *outReg[currDigit] |= setArr[currDigit];
    onTimes[currDigit] = micros();
    offTimes[currDigit] = 0;
    timeLastPressMicros =  onTimes[currDigit];
    currIndex++;
    currDigit = pgm_read_byte_near(pi + currIndex) - '0';
  }

  for (int i =0;i<10;i++){
    dummyTime = micros();
    if (dummyTime - onTimes[i] > BUTTONSLOWTOLERANCE && onTimes[i] !=0){
      onTimes[i] = 0;
      *outReg[i] &= resArr[i];
      offTimes[i] = micros();
    }
  }
}
