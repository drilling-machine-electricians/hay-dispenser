#include "LinearMotor.h"

LinearMotor::LinearMotor(Relais *forward, Relais *backward)
{
  relaisForward = forward;
  relaisBackward = backward;

  movingForward = false;
  movingBackward = false;
}

void LinearMotor::forward()
{
  movingForward = true;
  relaisForward->turnOn();
}

void LinearMotor::backward()
{
  movingBackward = true;
  relaisBackward->turnOn();
}

void LinearMotor::stop()
{
  if (isStopped())
  {
    return;
  }

  if (isMovingForward())
  {
    relaisForward->turnOff();
  }
  else
  {
    relaisBackward->turnOff();
  }

  movingForward = false;
  movingBackward = false;
}
