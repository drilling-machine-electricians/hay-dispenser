#ifndef HAY_DISPENSER_DIGITALOUTPUTIMAGE_H
#define HAY_DISPENSER_DIGITALOUTPUTIMAGE_H

#include <AbstractDigitalOutput.h>

class DigitalOutputImage : AbstractDigitalOutput {
public:
  DigitalOutputImage(AbstractDigitalOutput *output) { this->output = output; }
  void refresh() { output->turnOff(); }
  void turnOn() {}
  void turnOff() {}

private:
  AbstractDigitalOutput *output;
};

#endif
