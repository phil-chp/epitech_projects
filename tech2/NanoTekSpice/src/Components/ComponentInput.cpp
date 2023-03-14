/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** ComponentInput
*/

#include "Components/ComponentInput.hpp"

nts::ComponentInput::ComponentInput() : Component::Component()
{
    std::cout << "      + Input" << std::endl;
    this->setPin(); // 1
}

nts::ComponentInput::~ComponentInput()
{
}

void nts::ComponentInput::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::ComponentInput::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::ComponentInput::dump() const
{
    std::cout << "Input";
}
