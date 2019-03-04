#ifndef PLATFORM_IO_HANDSON_INDUCTIVESENSOR_H
#define PLATFORM_IO_HANDSON_INDUCTIVESENSOR_H

#include "DigitalInput.h"

class InductiveSensor {

public:
    InductiveSensor(DigitalInput *input);
    int isDampened();
private:
    DigitalInput *input;
};


#endif //PLATFORM_IO_HANDSON_INDUCTIVESENSOR_H
