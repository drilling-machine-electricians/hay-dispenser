#include "LinearMotor.h"

LinearMotor::LinearMotor(Relais *forward, Relais *backward)
{
  relaisForward = forward;
  relaisBackward = backward;

  relaisForward->turnOff();
  relaisBackward->turnOff();

  movingForward = false;
  movingBackward = false;
}

void LinearMotor::forward()
{
  if (!isStopped())
  {
    return;
  }

  movingForward = true;
  relaisForward->turnOn();
}

void LinearMotor::backward()
{
  if (!isStopped())
  {
    return;
  }

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
