/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Toy
*/

#include "Toy.hpp"

// ------------------------------ Subroutines ------------------------------- //

Toy::Toy()
    : _toyType(BASIC_TOY), _name("toy")
{
    _picture = Picture();
}

Toy::Toy(ToyType toyType, const std::string name, const std::string file)
    : _toyType(toyType), _name(name), _picture("")
{
    _picture = Picture(file);
}

Toy::~Toy()
{
}

// --------------------------- Getters & Setters ---------------------------- //

Toy::ToyType Toy::getType() const
{
    return (_toyType);
}

std::string Toy::getName() const
{
    return (_name);

}

std::string Toy::getAscii() const
{
    return (_picture.data);
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &file)
{
    _picture.getPictureFromFile(file);
    return (_picture.data != "ERROR");
}
