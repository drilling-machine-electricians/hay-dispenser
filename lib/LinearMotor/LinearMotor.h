#ifndef PLATFORM_IO_HANDSON_LINEARMOTOR_H
#define PLATFORM_IO_HANDSON_LINEARMOTOR_H

#include <AbstractRelais.h>

class LinearMotor
{
public:
  LinearMotor(AbstractRelais *forward, AbstractRelais *backward);

  void forward();
  void backward();
  void stop();

  bool isMovingForward() { return movingForward; }
  bool isMovingBackward() { return movingBackward; }
  bool isStopped() { return !isMovingForward() && !isMovingBackward(); }

private:
  AbstractRelais *relaisForward;
  AbstractRelais *relaisBackward;

  bool movingForward;
  bool movingBackward;
};

#endif //PLATFORM_IO_HANDSON_LINEARMOTOR_H
