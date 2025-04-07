#include "helpers.h"
#include "define.h"

int range = MAX - MIN;


int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000); // make sure Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      
  pinMode(8,OUTPUT); // For testing with LED
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  setDirection(IN1, IN2);
}

void loop() {
//  put your main code here, to run repeatedly:


  gamepad_Input();

  int x_axis  = /*analogRead(A0)*/ GamePad.getXaxisData();
  
  
  int y_axis = /*analogRead(A1)*/ GamePad.getYaxisData();
  if ( y_axis <= MID -1)
  {
    motorSpeedA = setSpeed(y_axis, MID - 1, MIN);
    motorSpeedB = motorSpeedA;
    setDirection(IN2, IN1);//Backwards
    setDirection(IN4, IN3);//Backwards
  }

  else if ( y_axis >= MID + 1)
  {
    motorSpeedA = setSpeed(y_axis, MID + 1, MAX);
    motorSpeedB = motorSpeedA;
    setDirection(IN1, IN2);//Forwards
    setDirection(IN3, IN4);//Forwards
  }

  else
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

  if (x_axis <= MID - 1)
  {
     
  }

 // testing purposes
  Serial.print("  MOTOR A: ");
  Serial.print(motorSpeedA);
  Serial.print("  MOTOR B: ");
  Serial.println(motorSpeedB);
  
  
   analogWrite(ENA, motorSpeedA);
  analogWrite(ENB, motorSpeedB);

  delay(20);
}
 //for making bluetooth work. Make sure to install "dabble" library in arduino IDE
