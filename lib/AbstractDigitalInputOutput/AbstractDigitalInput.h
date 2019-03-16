#ifndef HAY_DISPENSER_ABSTRACTDIGITALINPUT_H
#define HAY_DISPENSER_ABSTRACTDIGITALINPUT_H

class AbstractDigitalInput {
public:
  virtual ~AbstractDigitalInput() {}
  virtual bool isOn() = 0;
};

#endif
