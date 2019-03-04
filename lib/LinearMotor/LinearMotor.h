#ifndef PLATFORM_IO_HANDSON_LINEARMOTOR_H
#define PLATFORM_IO_HANDSON_LINEARMOTOR_H

#include "Relais.h"

class LinearMotor
{
public:
  LinearMotor(Relais *forward, Relais *backward);
  void forward();

private:
  Relais *relaisForward;
  Relais *relaisBackward;
};

#endif //PLATFORM_IO_HANDSON_LINEARMOTOR_H
