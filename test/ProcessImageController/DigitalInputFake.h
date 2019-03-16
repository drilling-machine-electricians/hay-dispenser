#ifndef HAY_DISPENSER_DIGITALINPUTFAKE_H
#define HAY_DISPENSER_DIGITALINPUTFAKE_H

#include "AbstractDigitalInput.h"

class DigitalInputFake : public AbstractDigitalInput {
public:
  DigitalInputFake() { status = false; }
  virtual ~DigitalInputFake() {}
  bool isOn() { return status; }
  bool status;
};
#endif
