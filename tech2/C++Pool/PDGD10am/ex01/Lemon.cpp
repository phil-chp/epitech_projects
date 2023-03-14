/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** Lemon
*/

#include "Lemon.hpp"

// ------------------------------ Subroutines ------------------------------- //

Lemon::Lemon() : Fruit("lemon", 3)
{
}

Lemon::Lemon(const std::string &name, int vitamins) : Fruit(name, vitamins)
{
}

Lemon::~Lemon()
{
}
