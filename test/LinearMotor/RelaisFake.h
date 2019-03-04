#ifndef HAY_DISPENSER_RELAISFAKE_H
#define HAY_DISPENSER_RELAISFAKE_H

#include <Relais.h>

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

#endif //HAY_DISPENSER_RELAISFAKE_H
