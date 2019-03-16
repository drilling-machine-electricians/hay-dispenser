#ifndef HAY_DISPENSER_DIGITALOUTPUTIMAGE_H
#define HAY_DISPENSER_DIGITALOUTPUTIMAGE_H

#include <AbstractDigitalOutput.h>

class DigitalOutputImage : public AbstractDigitalOutput {
public:
  DigitalOutputImage(AbstractDigitalOutput *output) {
    this->output = output;
    reset();
  }

  void refresh() {
    if (on) {
      output->turnOn();
    } else if (off) {
      output->turnOff();
    }

    reset();
  }

  void turnOn() {
    reset();
    on = true;
  }
  void turnOff() {
    reset();
    off = true;
  }

private:
  bool on;
  bool off;
  AbstractDigitalOutput *output;

  void reset() {
    on = false;
    off = false;
  }
};

#endif
