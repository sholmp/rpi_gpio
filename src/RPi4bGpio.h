#ifndef _RPI4B_GPIO_H_
#define _RPI4B_GPIO_H

#include "Gpio.h"
#include <filesystem>


class RPi4bGpio : public Gpio
{
public:
   RPi4bGpio(int pin_number, GpioMode mode);
   ~RPi4bGpio();

   void setDirection(GpioMode mode);
   GpioMode direction();
   void value();
   void write(bool value);

private:
    void exportPin(int pin_number);
    void setPinMode(GpioMode mode);

private:
    GpioMode mode_;
    int pin_number_;
    std::filesystem::path gpio_path_; // the specific pin's filepath e.g. 'sys/class/gpio/gpio12/'

};

#endif
