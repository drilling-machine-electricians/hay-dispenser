#ifndef PLATFORM_IO_HANDSON_LINEARMOTOR_H
#define PLATFORM_IO_HANDSON_LINEARMOTOR_H

#include "Relais.h"

class LinearMotor
{
public:
  LinearMotor(Relais *forward, Relais *backward);
  void forward();
  void backward();
  bool isMovingForward() { return movingForward; }

private:
  Relais *relaisForward;
  Relais *relaisBackward;
  bool movingForward;
};

#endif //PLATFORM_IO_HANDSON_LINEARMOTOR_H
