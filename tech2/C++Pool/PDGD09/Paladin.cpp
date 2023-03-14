/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int power)
    : Peasant(name, power), Knight(name, power), Priest(name, power)
{
    std::cout << getName() << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << getName() << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return (technique(10, " strikes with his sword.") ? 20 : 0);
}

int Paladin::special()
{
    return (technique(50, " casts a fireball.") ? 99 : 0);
}

void Paladin::rest()
{
    if (technique(-100, " prays."))
        setHp(100);
}
