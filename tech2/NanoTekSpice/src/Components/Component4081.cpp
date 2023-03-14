/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** Component4081
*/

#include "Components/Component4081.hpp"

nts::Component4081::Component4081() : Component::Component()
{
    std::cout << "      + 4081" << std::endl;
    this->setPin();       // 1
    this->setPin();       // 2
    this->setPin();       // 3
    this->setPin();       // 4
    this->setPin();       // 5
    this->setPin();       // 6
    this->setUnusedPin(); // 7
    this->setPin();       // 8
    this->setPin();       // 9
    this->setPin();       // 10
    this->setPin();       // 11
    this->setPin();       // 12
    this->setPin();       // 13
    this->setUnusedPin(); // 14
}

nts::Component4081::~Component4081()
{
}

void nts::Component4081::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::Component4081::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::Component4081::dump() const
{
    std::cout << "4081";
}
