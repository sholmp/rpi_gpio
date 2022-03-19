#include "RPi4bGpio.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;
namespace chrono = std::chrono;
using namespace std::chrono_literals; // to allow for writing '1ms' in sleep calls

namespace
{
    fs::path gpio_dir("/sys/class/gpio/");
}

using std::cout;
using std::endl;

RPi4bGpio::RPi4bGpio(int pin_number, GpioMode mode) : pin_number_(pin_number), mode_(mode)
{
    exportPin(pin_number);

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


// private methods
void RPi4bGpio::exportPin(int pin_number)
{
    auto path = gpio_dir / "export";
    std::ofstream export_file(path);
    if(export_file)
    {
        export_file << pin_number;
        std::this_thread::sleep_for(1ms);
    }
    else
    {
        cout << "could not open: " << path << endl;
    }
}


