/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power)
    : Peasant(name, power)
{
    std::cout << getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << getName() << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    technique(0, " doesn't know how to fight.");
    return (0);
}

int Enchanter::special()
{
    return (technique(50, " casts a fireball.") ? 99 : 0);
}

void Enchanter::rest()
{
    technique(-100, " meditates.");
}
