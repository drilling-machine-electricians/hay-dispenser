#ifndef HAY_DISPENSER_DIGITALOUTPUTRELAY_H
#define HAY_DISPENSER_DIGITALOUTPUTRELAY_H

#include "DigitalOutput.h"

class DigitalOutputRelais
{
public:
  DigitalOutputRelais(DigitalOutput *output);
  virtual void turnOn();
  virtual void turnOff();

protected:
  DigitalOutputRelais() {}

private:
  DigitalOutput *output;
};

#endif //HAY_DISPENSER_DIGITALOUTPUTRELAY_H
