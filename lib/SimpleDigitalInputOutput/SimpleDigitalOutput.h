#ifndef HAY_DISPENSER_SIMPLEDIGITALOUTPUT_H
#define HAY_DISPENSER_SIMPLEDIGITALOUTPUT_H

#include <AbstractDigitalOutput.h>
#include <Arduino.h>

class SimpleDigitalOutput : public AbstractDigitalOutput {
public:
  SimpleDigitalOutput(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
  }
  virtual ~SimpleDigitalOutput() {}

  virtual void turnOff() { digitalWrite(LED_BUILTIN, HIGH); }
  virtual void turnOn() { digitalWrite(LED_BUILTIN, LOW); }

private:
  int pin;
};

#endif
