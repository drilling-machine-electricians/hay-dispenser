#include "DigitalOutputRelais.h"

DigitalOutputRelais::DigitalOutputRelais(DigitalOutput *output)
{
  this->output = output;
}

void DigitalOutputRelais::turnOn()
{
  this->output->set(false);
}

void DigitalOutputRelais::turnOff()
{
  this->output->set(true);
}
