#include <Arduino.h>
#include <stddef.h>

#include <ProcessImageController.h>
#include <SimpleDigitalInput.h>

ProcessImageController *processImageController = NULL;

void setup() {
  processImageController = new ProcessImageController();
  processImageController->registerInput(new SimpleDigitalInput());
  processImageController->registerInput(new SimpleDigitalInput());
  processImageController->registerInput(new SimpleDigitalInput());
  processImageController->registerInput(new SimpleDigitalInput());
}

void loop() {
  processImageController->read();
  _delay_ms(500);
}
