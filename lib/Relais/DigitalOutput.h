#ifndef PLATFORM_IO_HANDSON_DIGITALOUTPUT_H
#define PLATFORM_IO_HANDSON_DIGITALOUTPUT_H

class DigitalOutput {
public:
    virtual void set(int state) = 0;
};

#endif //PLATFORM_IO_HANDSON_DIGITALOUTPUT_H
