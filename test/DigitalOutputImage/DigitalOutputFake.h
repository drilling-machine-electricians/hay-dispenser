#ifndef HAY_DISPENSER_DIGITALOUTPUTFAKE_H
#define HAY_DISPENSER_DIGITALOUTPUTFAKE_H

#include <AbstractDigitalOutput.h>

class DigitalOutputFake : public AbstractDigitalOutput {
public:
  DigitalOutputFake() {
    turnedOn = false;
    turnedOff = false;
  }
  virtual ~DigitalOutputFake() {}
  void turnOn() { turnedOn = true; }
  void turnOff() { turnedOff = true; }
  bool turnedOn;
  bool turnedOff;
};
#endif
