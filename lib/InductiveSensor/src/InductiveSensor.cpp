#include "InductiveSensor.h"

InductiveSensor::InductiveSensor(DigitalInput *input) {
    this->input = input;
}

int InductiveSensor::isDampened() {
    return input->get() == 0;
}