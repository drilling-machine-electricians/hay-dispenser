#ifndef HAY_DISPENSER_RELAISFAKE_H
#define HAY_DISPENSER_RELAISFAKE_H

#include <AbstractRelais.h>

class RelaisFake : public AbstractRelais
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
