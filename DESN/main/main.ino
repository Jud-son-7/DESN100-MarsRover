#include "helpers.h"
#include "define.h"

int range = MAX - MIN;


int rightMotors = 0;
int leftMotors = 0;

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
    rightMotors = setSpeed(y_axis, MID - 1, MIN);
    leftMotors = rightMotors;
    setDirection(IN2, IN1);//Backwards
    setDirection(IN4, IN3);//Backwards
  }

  else if ( y_axis >= MID + 1)
  {
    rightMotors = setSpeed(y_axis, MID + 1, MAX);
    leftMotors = rightMotors;
    setDirection(IN1, IN2);//Forwards
    setDirection(IN3, IN4);//Forwards
  }

  else
  {
    rightMotors = 0;
    leftMotors = 0;
  }

  if (x_axis <= MID - 1)
  {
     int diff = setSpeed(x_axis, MID - 1, MIN);
     rightMotors += diff;
     leftMotors -= diff;

     leftMotors = leftMotors <= 30 ? 0: leftMotors;
     rightMotors = rightMotors >= 255 ? 255 : rightMotors;
  }

  else if (x_axis >= MID + 1)
  {
    int diff = setSpeed(x_axis, MID + 1, MAX);
     rightMotors -= diff;
     leftMotors += diff;

     rightMotors = rightMotors <= 30 ? 0: rightMotors;
     leftMotors = leftMotors >= 255 ? 255 : leftMotors;
  }

 // testing purposes
  Serial.print("  MOTOR A: ");
  Serial.print(rightMotors);
  Serial.print("  MOTOR B: ");
  Serial.println(leftMotors);
  
  
  analogWrite(ENA, rightMotors);
  analogWrite(ENB, leftMotors);

  delay(20);
}
 //for making bluetooth work. Make sure to install "dabble" library in arduino IDE
