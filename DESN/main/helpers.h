#ifndef HELPERS_H
#define HELPERS_H
#include "Arduino.h"
#include "define.h"


int setSpeed(int value, int min, int max)
{
  int speed = map(value, min, max, 0, 255);
  return speed;
}

void setDirection(int in1, int in2)
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void gamepad_Input(void) //detects input from gamepad app
{
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.
  if (GamePad.isUpPressed())
  {
    Serial.print("KeyPressed: UP");
    Serial.println();
    
    //put drive forward here
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("KeyPressed: DOWN ");
    Serial.println();
    //put drive backwards here
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("KeyPressed: LEFT ");
    Serial.println();
    //put turn left here
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("KeyPressed: RIGHT ");
    Serial.println();
    //put turn right here
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("KeyPressed: SQUARE");
    Serial.println();

    excavator.write(30);
    delay(1000);
    //lower excavator
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("KeyPressed: CIRCLE");
    Serial.println();
    //lower trapdoor down here

    trapdoor.write(45);
    delay(1000);
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("KeyPressed: CROSS");
    Serial.println();
    //lift trapdoor up

    trapdoor.write(45);
    delay(1000);
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("KeyPressed: TRIANGLE");
    Serial.println();
    //lift excavator up

    excavator.write(135);
    delay(1000);
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("KeyPressed: START");
    Serial.println();
    //horn
    digitalWrite(8,HIGH); //turns LED on
  } else {
    digitalWrite(8,LOW); //turns LED off when button is not pressed
  }
  
  if (GamePad.isSelectPressed())
  {
    Serial.print("KeyPressed: SELECT");
    Serial.println();
  }
}

#endif