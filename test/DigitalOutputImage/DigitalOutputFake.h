#ifndef HAY_DISPENSER_DIGITALOUTPUTFAKE_H
#define HAY_DISPENSER_DIGITALOUTPUTFAKE_H

#include <AbstractDigitalOutput.h>

class DigitalOutputFake : public AbstractDigitalOutput {
public:
  DigitalOutputFake() {}
  virtual ~DigitalOutputFake() {}
  void turnOn() {}
  void turnOff() {}
};
#endif
