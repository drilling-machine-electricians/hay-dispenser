#include <Arduino.h>
#include <stddef.h>

#include <ProcessImageController.h>
#include <SimpleDigitalInput.h>

ProcessImageController *processImageController = NULL;
AbstractDigitalInput *inputLowSensor = NULL;
AbstractDigitalInput *inputHighSensor = NULL;

void setup() {
  processImageController = new ProcessImageController();
  inputLowSensor =
      processImageController->registerInput(new SimpleDigitalInput());
  inputHighSensor =
      processImageController->registerInput(new SimpleDigitalInput());
  processImageController->registerInput(new SimpleDigitalInput());
}

void loop() {
  processImageController->read();
  _delay_ms(500);
  _delay_ms(500);

  _delay_ms(500);
  _delay_ms(500);
  processImageController->write();
}
