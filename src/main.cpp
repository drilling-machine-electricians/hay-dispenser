#include <Arduino.h>
#include <stddef.h>

#include <DigitalOutputImage.h>
#include <ProcessImageController.h>
#include <SimpleDigitalInput.h>
#include <SimpleDigitalOutput.h>

ProcessImageController *processImageController = NULL;
SimpleDigitalOutput *internalLed = NULL;
DigitalOutputImage *internalLedImage = NULL;
AbstractDigitalInput *inputLowSensor = NULL;
AbstractDigitalInput *inputHighSensor = NULL;

void setup() {
  processImageController = new ProcessImageController();
  inputLowSensor =
      processImageController->registerInput(new SimpleDigitalInput());
  inputHighSensor =
      processImageController->registerInput(new SimpleDigitalInput());
  processImageController->registerInput(new SimpleDigitalInput());
  internalLed = new SimpleDigitalOutput(LED_BUILTIN);
  internalLedImage = new DigitalOutputImage(internalLed);
}

void loop() {
  internalLedImage->turnOff();
  internalLedImage->refresh();
  internalLedImage->turnOn();
  _delay_ms(500);
  _delay_ms(500);
  _delay_ms(500);
  _delay_ms(500);
  internalLedImage->refresh();
  _delay_ms(500);
  _delay_ms(500);
}
