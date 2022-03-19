#ifndef _GPIO_H_
#define _GPIO_H_

enum class GpioMode
{
    Input,
    Output
};

class Gpio
{
public:
    virtual void setDirection(GpioMode mode) = 0;
    virtual void read() = 0;
    virtual void write(bool value) = 0;
};

#endif