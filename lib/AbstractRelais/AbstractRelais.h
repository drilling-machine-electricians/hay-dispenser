#ifndef HAY_DISPENSER_ABSTRACTRELAIS_H
#define HAY_DISPENSER_ABSTRACTRELAIS_H

class AbstractRelais
{
public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

#endif //HAY_DISPENSER_ABSTRACTRELAIS_H
