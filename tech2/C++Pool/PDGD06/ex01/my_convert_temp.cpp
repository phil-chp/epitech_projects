/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** my_convert_temp
*/

#include <iostream>
#include <cstring>
// #include <string>
#include <iomanip>

int my_convert_temp(float temperature, char *format)
{
    if (std::strcmp(format, "Fahrenheit") == 0) {
        float f = 5.0 / 9.0 * (temperature - 32.0);
        std::cout
            << std::setw(16)
            << std::fixed << std::setprecision(3) << f
            << std::setw(16)
            << "Celsius"
            << std::endl;
    } else if (std::strcmp(format, "Celsius") == 0) {
        float c = (temperature * 9.0 / 5.0) + 32.0;
        std::cout
            << std::setw(16)
            << std::fixed << std::setprecision(3) << c
            << std::setw(16)
            << "Fahrenheit"
            << std::endl;
    } else {
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    char format[64];
    float temperature;

    std::cin >> temperature >> format;

    if (my_convert_temp(temperature, format)) {
        std::cerr
            << av[0]
            << ": Wrong temperature format."
            << std::endl
            << "Use 'Fahrenheit' or 'Celsius'."
            << std::endl;
    }
    return (0);
}

// Celsius = 5.0 / 9.0 * (Fahrenheit - 32)
