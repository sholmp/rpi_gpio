#include <gtest/gtest.h>
#include <filesystem>

#define private public // hack to access private members ;-)
#include "RPi4bGpio.h"


TEST(GpioTest, FilePaths)
{
    RPi4bGpio pin12(12, GpioMode::Input);
    auto expected_path = std::filesystem::path("/sys/class/gpio/gpio12");
    EXPECT_EQ(pin12.gpio_path_, expected_path);
}