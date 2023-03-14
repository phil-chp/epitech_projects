/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** DateTimeModule
*/

#ifndef CLOCKMODULE_HPP_
#define CLOCKMODULE_HPP_

#include "Configurable.hpp"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

typedef struct ClockModuleConfig
{
    std::string date;
} ClockModuleConfig;

class ClockModule : public Configurable<ClockModuleConfig>
{
    public:
        ClockModule();
        ~ClockModule();
        void refresh();
        void getData();
};

#endif /* !CLOCKMODULE_HPP_ */
