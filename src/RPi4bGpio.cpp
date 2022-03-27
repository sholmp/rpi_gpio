#include "RPi4bGpio.h"
#include "Logger.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <fmt/format.h>

namespace fs = std::filesystem;
namespace chrono = std::chrono;
using namespace std::chrono_literals; // to allow for writing '1ms' in sleep calls

namespace
{
    fs::path sysfs_gpio_dir("/sys/class/gpio/");
}

using std::cout;
using std::endl;

RPi4bGpio::RPi4bGpio(int pin_number, GpioMode mode) : pin_number_(pin_number), mode_(mode)
{
    exportPin(pin_number); 
    // after exporting the pin, linux should create the specific pin dir, e.g. 'sys/class/gpio/gpio12/'
    // we sleep for a brief moment to allow this to happen
    std::this_thread::sleep_for(1ms);
    gpio_path_ = sysfs_gpio_dir / (std::string("gpio") + std::to_string(pin_number)); // 'sys/class/gpio/gpio12/'
    if(!fs::exists(gpio_path_))
    {
        fmt::print("Linux did not create directory: {}\n", gpio_path_.string());
    }

    // new idea: 
    // open all files in gpio_dir_ and hold on to them for the existance of this object

}

void RPi4bGpio::setDirection(GpioMode mode)
{
    std::ofstream(sysfs_gpio_dir / "direction");
    if(mode == GpioMode::Input)
    {

    }
}

GpioMode RPi4bGpio::direction()
{
    // read the file sys/class/gpio/gpio12/direction
    return GpioMode::Input;
}

void RPi4bGpio::value()
{
}

void RPi4bGpio::write(bool value)
{
}

RPi4bGpio::~RPi4bGpio()
{
    cout << "destroyed. Here we should unexport the pin as well" << endl;
}

// private methods
void RPi4bGpio::exportPin(int pin_number)
{
    auto path = sysfs_gpio_dir / "export";
    std::ofstream export_file(path);
    if(export_file; export_file << pin_number)
        ;
    else
    {
        cout << "could not open: " << path << endl;
    }
}


