/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(const std::string name)
{
    SickKoala::_name = name;
}

SickKoala::~SickKoala(void)
{
    std::cout
        << "Mr."
        << _name
        <<": Kreooogg!! I'm cuuuured!"
        << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << _name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string food)
{
    if (food.compare("Kinder") == 0) {
        std::cout << "Mr." << _name << ": There is a toy inside!" << std::endl;
    } else if (food.compare("Mars") == 0) {
        std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
    } else {
        std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
        return (false);
    }
    return (true);
}

void SickKoala::overDrive(std::string message)
{
    size_t pos;

    pos = message.find("Kreog!");
    while (pos != std::string::npos) {
        message = message.replace(pos, 6, "1337!");
        pos = message.find("Kreog!");
    }
    std::cout << "Mr." << _name << ": " << message << std::endl;
}

std::string SickKoala::getName(void)
{
    return _name;
}
