#ifndef HAY_DISPENSER_DIGITALINPUTIMAGE_H
#define HAY_DISPENSER_DIGITALINPUTIMAGE_H

#include <AbstractDigitalInput.h>

class DigitalInputImage : public AbstractDigitalInput
{
public:
  DigitalInputImage(AbstractDigitalInput *input);
  ~DigitalInputImage();
  virtual bool isOn() { return status; }

  void refresh();

private:
  AbstractDigitalInput *input;
  bool status;
};

#endif // HAY_DISPENSER_DIGITALINPUTIMAGE_H
