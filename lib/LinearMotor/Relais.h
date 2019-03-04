#ifndef HAY_DISPENSER_RELAIS_H
#define HAY_DISPENSER_RELAIS_H

class Relais
{
public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

#endif //HAY_DISPENSER_RELAIS_H
