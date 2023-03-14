/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Peasant
*/

#include "Peasant.hpp"

// ------------------------------ Subroutines ------------------------------- //

Peasant::Peasant(const std::string &name, int power)
    : _name(name), _power(power), _hp(100)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

// --------------------------- Getters & Setters ---------------------------- //

const std::string &Peasant::getName() const
{
    return (_name);
}

int Peasant::getPower() const
{
    return (_power);
}

int Peasant::getHp() const
{
    return (_hp);
}

void Peasant::setHp(int hp)
{
    _hp = hp;
}

// -------------------------------- Methods --------------------------------- //

bool Peasant::technique(int powerCost, const std::string &message)
{
    std::string errorMessage = "";

    if (_hp <= 0)
        errorMessage = " is out of combat.";
    if ((_power < 0 || _power < powerCost) && errorMessage.length() == 0)
        errorMessage = " is out of power.";
    if (errorMessage.length() > 0) {
        std::cout << _name << errorMessage << std::endl;
        return (false);
    }
    _power -= powerCost;
    _power = (_power > 100 ? 100 : _power);
    std::cout << _name << message << std::endl;
    return (true);
}

int Peasant::attack()
{
    return (technique(10, " tosses a stone.") ? 5 : 0);
}

int Peasant::special()
{
    technique(0, " doesn't know any special move.");
    return (0);
}

void Peasant::rest()
{
    technique(-30, " takes a nap.");
}

void Peasant::damage(int damage)
{
    _hp -= damage;
    _hp = (_hp > 100 ? 100 : (_hp < 0 ? 0 : _hp));
    if (_hp > 0) {
        std::cout << _name << " takes " << damage << " damage." << std::endl;
    } else {
        std::cout << _name << " is out of combat." << std::endl;
    }
}
