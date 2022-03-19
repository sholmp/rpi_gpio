#include "RPi4bGpio.h"
#include <iostream>

using std::cout;
using std::endl;


RPi4bGpio::RPi4bGpio(int pin_number, GpioMode mode): pin_number_(pin_number), mode_(mode)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void RPi4bGpio::setDirection(GpioMode mode)
{

}

void RPi4bGpio::read()
{

}

void RPi4bGpio::write(bool value)
{

}
