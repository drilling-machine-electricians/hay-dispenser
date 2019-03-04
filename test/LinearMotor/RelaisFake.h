#include "Relais.h"

class RelaisFake : public Relais
{
public:
  RelaisFake()
  {
    turnedOff = false;
    turnedOn = false;
  }
  void turnOn()
  {
    turnedOn = true;
  }

  void turnOff()
  {
    turnedOff = true;
  }

  bool turnedOn;
  bool turnedOff;
};
