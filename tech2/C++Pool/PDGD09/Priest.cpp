/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int power)
    : Peasant(name, power), Enchanter(name, power)
{
    std::cout << getName() << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << getName() << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (technique(-100, " prays."))
        setHp(100);
}
