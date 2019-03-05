#include "ProcessImageController.h"

DigitalInputImage *ProcessImageController::registerInput(AbstractDigitalInput *input)
{
  image = new DigitalInputImage(input);
  return image;
}

void ProcessImageController::read()
{
  image->refresh();
}
