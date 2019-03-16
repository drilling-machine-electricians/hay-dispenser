#ifndef HAY_DISPENSER_PROCESSIMAGECONTROLLER_H
#define HAY_DISPENSER_PROCESSIMAGECONTROLLER_H

#include "DigitalInputImage.h"
#include "DigitalOutputImage.h"
#include <AbstractDigitalInput.h>
#include <AbstractDigitalOutput.h>

const int MAX_SIZE = 4;

class ProcessImageController {
public:
  ProcessImageController();
  AbstractDigitalInput *registerInput(AbstractDigitalInput *input);
  AbstractDigitalOutput *registerOutput(AbstractDigitalOutput *output);
  void read();
  void write() {}

private:
  DigitalInputImage *image[MAX_SIZE];
  int size;
};

#endif
