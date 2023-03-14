/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** Fruit
*/

#include "Fruit.hpp"

// ------------------------------ Subroutines ------------------------------- //

Fruit::Fruit(std::string name, int vitamins)
    : _name(name), _vitamins(vitamins)
{
}

Fruit::~Fruit()
{
}

// -------------------------------- Methods --------------------------------- //

int Fruit::getVitamins() const
{
    return _vitamins;
}

const std::string Fruit::getName() const
{
    return _name;
}
