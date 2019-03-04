#include "LinearMotor.h"

LinearMotor::LinearMotor(Relais *forward, Relais *backward)
{
  relaisForward = forward;
  relaisBackward = backward;

  movingForward = false;
}

void LinearMotor::forward()
{
  movingForward = true;
  relaisForward->turnOn();
}

void LinearMotor::backward()
{
  relaisBackward->turnOn();
}
