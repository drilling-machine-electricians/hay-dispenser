#ifndef HAY_DISPENSER_DIGITALOUTPUTIMAGE_H
#define HAY_DISPENSER_DIGITALOUTPUTIMAGE_H

#include <AbstractDigitalOutput.h>

class DigitalOutputImage : AbstractDigitalOutput {
public:
  DigitalOutputImage(AbstractDigitalOutput *output) {
    this->output = output;
    this->on = false;
  }
  void refresh() {
    if (on) {
      output->turnOn();
    } else {
      output->turnOff();
    }
  }
  void turnOn() { on = true; }
  void turnOff() {}

private:
  bool on = false;
  AbstractDigitalOutput *output;
};

#endif
