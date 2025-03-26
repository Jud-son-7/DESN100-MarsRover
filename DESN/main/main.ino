#include "helpers.h"
#include "define.h"



int range = MAX - MIN;
int MID = range/2;


int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  setDirection(IN1, IN2);
}

void loop() {
//  put your main code here, to run repeatedly:

  int x_axis  = analogRead(A0);
  
  
  int y_axis = analogRead(A1);
  if ( y_axis <= MID - (0.1*range))
  {
    motorSpeedA = setSpeed(y_axis, MID - (0.05*range),  MIN);
    motorSpeedB = motorSpeedA;
    setDirection(IN2, IN1);//Backwards
    setDirection(IN4, IN3);//Backwards
  }

  else if ( y_axis >= MID + (0.1*range))
  {
    motorSpeedA = setSpeed(y_axis, MID + (0.05*range), MAX);
    motorSpeedB = motorSpeedA;
    setDirection(IN1, IN2);//Forwards
    setDirection(IN3, IN4);//Forwards
  }

  else
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }
 
  Serial.print("  MOTOR A: ");
  Serial.print(motorSpeedA);
  Serial.print("  MOTOR B: ");
  Serial.println(motorSpeedB);
  
  
  analogWrite(ENA, motorSpeedA);
  analogWrite(ENB, motorSpeedB);

  delay(20);
}

