#ifndef PLATFORM_IO_HANDSON_DIGITALOUTPUTMOCK_H
#define PLATFORM_IO_HANDSON_DIGITALOUTPUTMOCK_H

#include <DigitalOutput.h>

class DigitalOutputMock : public DigitalOutput {
public:
    DigitalOutputMock() { this->calls = 0; };
    void set(int state) {
        this->calls++;
        this->callValue = state;
    };
    int calls;
    int callValue;
};

#endif //PLATFORM_IO_HANDSON_DIGITALOUTPUTMOCK_H
