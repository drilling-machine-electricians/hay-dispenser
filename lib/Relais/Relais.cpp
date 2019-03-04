#include "Relais.h"

Relais::Relais(DigitalOutput *output) {
    this->output = output;
}

void Relais::turnOn() {
    this->output->set(false);
}

void Relais::turnOff() {
    this->output->set(true);
}
