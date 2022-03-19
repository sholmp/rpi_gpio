#include <iostream>
#include "RPi4bGpio.h"


int main()
{
    RPi4bGpio p(5, GpioMode::Output);
    RPi4bGpio pin10(12, GpioMode::Input);
    std::cout << "hell world"  << std::endl;
    return 0;
}