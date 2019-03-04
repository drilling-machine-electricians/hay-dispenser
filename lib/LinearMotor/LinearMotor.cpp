#include "LinearMotor.h"

LinearMotor::LinearMotor(Relais *forward, Relais *backward)
{
  relaisForward = forward;
  relaisBackward = backward;
}

void LinearMotor::forward()
{
  relaisForward->turnOn();
}
