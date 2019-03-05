#ifndef HAY_DISPENSER_PROCESSIMAGECONTROLLER_H
#define HAY_DISPENSER_PROCESSIMAGECONTROLLER_H

#include <AbstractDigitalInput.h>
#include "DigitalInputImage.h"

const int MAX_SIZE = 4;

class ProcessImageController
{
public:
  ProcessImageController();
  DigitalInputImage *registerInput(AbstractDigitalInput *input);
  void read();

private:
  DigitalInputImage *image[MAX_SIZE];
  int size;
};

#endif
