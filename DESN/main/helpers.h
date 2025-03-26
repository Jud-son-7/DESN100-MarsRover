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
#endif