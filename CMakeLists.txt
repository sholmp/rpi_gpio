project(rpi_gpio)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)


# The main library to be built
set(GPIO_LIB rpi_gpio)
set(gpio_sources
    src/Gpio.h
    src/RPi4bGpio.cpp
    src/RPi4bGpio.h)
add_library(${GPIO_LIB} ${gpio_sources})
target_link_libraries(${GPIO_LIB} fmt)


# Program to be linked with the built library
set(RUNNER_TARGET runner)
add_executable(${RUNNER_TARGET} test/main.cpp)
target_include_directories(${RUNNER_TARGET}  PUBLIC src)
target_link_libraries(${RUNNER_TARGET} ${GPIO_LIB})

# Unit tests
enable_testing()
set(TEST_TARGET gpio_test)
add_executable(${TEST_TARGET} test/gpio_test.cpp)
target_link_libraries(${TEST_TARGET} ${GPIO_LIB} gtest gtest_main pthread)
target_include_directories(${TEST_TARGET} PUBLIC src)
add_test(NAME ${TEST_TARGET} COMMAND ${TEST_TARGET}) # now you can write 'make test' and run the test target