project(rpi_gpio)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)


# The main library to be built
set(gpio_sources
    src/Gpio.h
    src/RPi4bGpio.cpp
    src/RPi4bGpio.h)
add_library(rpi_gpio ${gpio_sources})


# Program to be linked with the built library
add_executable(runner test/main.cpp)
target_include_directories(runner PUBLIC src)
target_link_libraries(runner rpi_gpio)
