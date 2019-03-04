#ifndef PLATFORM_IO_HANDSON_INPUTFAKE_H
#define PLATFORM_IO_HANDSON_INPUTFAKE_H

#include <DigitalInput.h>

class DigitalInputFake : public DigitalInput {
public:
    DigitalInputFake() {}

    int get() { return result; }

    void setValue(int result) { this->result = result; }

private:
    int result;
};


#endif //PLATFORM_IO_HANDSON_INPUTFAKE_H
