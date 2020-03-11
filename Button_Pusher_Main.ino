#include<avr/pgmspace.h>

#define BUTTONFASTTOLERANCE .01*1000000//time between press of different buttons
#define BUTTONSLOWTOLERANCE .025*1000000//button debounce time


unsigned long onTimes[10], offTimes[10];
uint8_t setArr[] = {B00000100,B00001000,B00010000,B00100000,B01000000,B10000000,B00000001,B00000010,B00000100,B00001000};
uint8_t resArr[] = {B11111011,B11110111,B11101111,B11011111,B10111111,B01111111,B11111110,B11111101,B11111011,B11110111};
uint8_t *outReg[] = {&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTD,&PORTB,&PORTB,&PORTB,&PORTB};
unsigned long timeLastPressMicros, dummyTime;
unsigned int currDigit = 3;
int currIndex = 0;


void setup() {
  pinMode(2,OUTPUT);  //DIGIT 0
  pinMode(3,OUTPUT);  //DIGIT 1
  pinMode(4,OUTPUT);  //DIGIT 2
  pinMode(5,OUTPUT);  //DIGIT 3
  pinMode(6,OUTPUT);  //DIGIT 4
  pinMode(7,OUTPUT);  //DIGIT 5
  pinMode(8,OUTPUT);  //DIGIT 6
  pinMode(9,OUTPUT);  //DIGIT 7
  pinMode(10,OUTPUT); //DIGIT 8
  pinMode(11,OUTPUT); //DIGIT 9

  for (int i = 0;i<10;i++){
    onTimes[i] = 1;
    offTimes[i] = 1;
  }
  
  Serial.begin(9600);
  Serial.println("hello");
  Serial.println(BUTTONSLOWTOLERANCE);
  
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

void loop(){
 
  
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
      Serial.println(dummyTime-onTimes[i]);
      onTimes[i] = 0;
      *outReg[i] &= resArr[i];
      offTimes[i] = micros();
    }
  }
}
