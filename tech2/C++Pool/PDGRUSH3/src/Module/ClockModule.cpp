/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** ClockModule
*/

#include "ClockModule.hpp"

ClockModule::~ClockModule()
{
    // do nothing
};

ClockModule::ClockModule()
{
    ClockModuleConfig *date_time = new ClockModuleConfig;

    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::string time_tmp = std::ctime(&time_now);
    time_tmp.erase(std::remove(time_tmp.begin(), time_tmp.end(), '\n'), time_tmp.end());

    date_time->date = time_tmp;
    this->setConfig(date_time);
}

void ClockModule::getData()
{
    ClockModuleConfig *date_time = new ClockModuleConfig;

    auto now = std::chrono::system_clock::now();
    std::time_t time_now = std::chrono::system_clock::to_time_t(now);
    std::string time_tmp = std::ctime(&time_now);
    time_tmp.erase(std::remove(time_tmp.begin(), time_tmp.end(), '\n'), time_tmp.end());

    date_time->date = time_tmp;
    this->setConfig(date_time);
}

void ClockModule::refresh()
{
}
