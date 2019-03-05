#ifndef HAY_DISPENSER_PROCESSIMAGECONTROLLER_H
#define HAY_DISPENSER_PROCESSIMAGECONTROLLER_H

#include <AbstractDigitalInput.h>
#include "DigitalInputImage.h"

const int MAX_INPUT_SIXE = 10;

class ProcessImageController
{
public:
  DigitalInputImage *registerInput(AbstractDigitalInput *input);
  void read();

private:
  DigitalInputImage *image;
};

#endif
