#ifndef PLATFORM_IO_HANDSON_RELAIS_H
#define PLATFORM_IO_HANDSON_RELAIS_H

#include "DigitalOutput.h"

class Relais
{
public:
  Relais(DigitalOutput *output);
  void turnOn();
  void turnOff();

protected:
  Relais() {}

private:
  DigitalOutput *output;
};

#endif //PLATFORM_IO_HANDSON_RELAIS_H
