/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(const std::string &name, int power)
    : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << getName() << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    return (technique(10, " strikes with his sword.") ? 20 : 0);
}

int Knight::special()
{
    return (technique(30, " impales his enemy.") ? 50 : 0);
}

void Knight::rest()
{
    technique(-50, " eats.");
}
