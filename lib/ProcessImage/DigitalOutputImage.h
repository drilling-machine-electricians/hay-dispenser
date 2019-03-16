#ifndef HAY_DISPENSER_DIGITALOUTPUTIMAGE_H
#define HAY_DISPENSER_DIGITALOUTPUTIMAGE_H

#include <AbstractDigitalOutput.h>

class DigitalOutputImage : AbstractDigitalOutput {
public:
  DigitalOutputImage(AbstractDigitalOutput *output) {
    this->output = output;
    this->on = false;
    this->off = false;
  }
  void refresh() {
    if (on) {
      output->turnOn();
    }
    if (off) {
      output->turnOff();
    }

    on = false;
    off = false;
  }
  void turnOn() { on = true; }
  void turnOff() { off = true; }

private:
  bool on;
  bool off;
  AbstractDigitalOutput *output;
};

#endif
