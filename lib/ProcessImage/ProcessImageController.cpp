#include "ProcessImageController.h"

ProcessImageController::ProcessImageController() { size = 0; }

AbstractDigitalInput *
ProcessImageController::registerInput(AbstractDigitalInput *input) {
  image[size] = new DigitalInputImage(input);
  size++;

  return image[size - 1];
}

void ProcessImageController::read() {
  for (int i = 0; i < size; i++) {
    image[i]->refresh();
  }
}

AbstractDigitalOutput *
ProcessImageController::registerOutput(AbstractDigitalOutput *output) {
  AbstractDigitalOutput *asdf = new DigitalOutputImage(output);
  return asdf;
}
