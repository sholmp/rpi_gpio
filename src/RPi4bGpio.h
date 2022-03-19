#ifndef _RPI4B_GPIO_H_
#define _RPI4B_GPIO_H

#include "Gpio.h"

class RPi4bGpio : public Gpio
{
public:
   RPi4bGpio(int pin_number, GpioMode mode);

   void setDirection(GpioMode mode);
   void read();
   void write(bool value);

private:
    GpioMode mode_;
    int pin_number_;
};

#endif
