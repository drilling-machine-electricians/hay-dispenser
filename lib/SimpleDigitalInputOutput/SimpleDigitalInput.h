#ifndef HAY_DISPENSER_SIMPLEDIGITALINPUT_H
#define HAY_DISPENSER_SIMPLEDIGITALINPUT_H

#include "AbstractDigitalInput.h"

class SimpleDigitalInput : public AbstractDigitalInput {
public:
  SimpleDigitalInput() {}
  virtual ~SimpleDigitalInput() {}
  virtual bool isOn() { return true; }
};

#endif
