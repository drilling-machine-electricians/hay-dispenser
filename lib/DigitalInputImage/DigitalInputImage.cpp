#include "DigitalInputImage.h"

DigitalInputImage::DigitalInputImage(AbstractDigitalInput *input)
{
  this->input = input;
  status = false;
}

DigitalInputImage::~DigitalInputImage()
{
}

void DigitalInputImage::refresh()
{
  status = input->isOn();
}
