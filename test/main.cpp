#include <iostream>
#include "RPi4bGpio.h"


int main()
{
    RPi4bGpio p(5, GpioMode::Output);

    return 0;
}