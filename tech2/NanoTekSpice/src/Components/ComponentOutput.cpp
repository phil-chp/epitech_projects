/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** ComponentOutput
*/

#include "Components/ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput() : Component::Component()
{
    std::cout << "      + Output" << std::endl;
    this->setPin(); // 1
}

nts::ComponentOutput::~ComponentOutput()
{
}

void nts::ComponentOutput::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::ComponentOutput::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::ComponentOutput::dump() const
{
    std::cout << "Output";
}
