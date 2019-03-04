#ifndef PLATFORM_IO_HANDSON_LINEARMOTOR_H
#define PLATFORM_IO_HANDSON_LINEARMOTOR_H

#include "Relais.h"

class LinearMotor
{
public:
  LinearMotor(Relais *forward, Relais *backward);
  void forward();
  void backward();

  void stop();

  bool isMovingForward() { return movingForward; }
  bool isMovingBackward() { return movingBackward; }

  bool isStopped() { return !isMovingForward() && !isMovingBackward(); }

private:
  Relais *relaisForward;
  Relais *relaisBackward;
  bool movingForward;
  bool movingBackward;
};

#endif //PLATFORM_IO_HANDSON_LINEARMOTOR_H
