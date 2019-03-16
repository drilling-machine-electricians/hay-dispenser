#ifndef HAY_DISPENSER_ABSTRACTDIGITALOUTPUT_H
#define HAY_DISPENSER_ABSTRACTDIGITALOUTPUT_H

class AbstractDigitalOutput {
public:
  virtual ~AbstractDigitalOutput() {}
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

#endif
