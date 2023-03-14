/*
** EPITECH PROJECT, 2022
** PDG-D10-PM (Workspace)
** File description:
** Oxygenator
*/

#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator() :
    _quantity(0)
{
}

void Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void Oxygenator::useOxygen(int quantity)
{
    if (_quantity - quantity <= 5)
        throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
    if (_quantity - quantity <= 20)
        throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");
    _quantity -= quantity;
}
