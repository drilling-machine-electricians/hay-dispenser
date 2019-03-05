#include "ProcessImageController.h"

ProcessImageController::ProcessImageController()
{
  size = 0;
}

DigitalInputImage *ProcessImageController::registerInput(AbstractDigitalInput *input)
{
  image[size] = new DigitalInputImage(input);
  size++;

  return image[size - 1];
}

void ProcessImageController::read()
{
  for (int i = 0; i < size; i++)
  {
    image[i]->refresh();
  }
}
