/*
** EPITECH PROJECT, 2022
** PDG-D8 (Workspace)
** File description:
** Droid
*/

#include "Droid.hpp"

// ------------------------------ Subroutines ------------------------------- //

Droid::Droid(std::string id)                                    \
    : _id(id), _energy(50), _attack(25),                        \
    _toughness(15), _status(new std::string("Standing by")),    \
    _battleData(new DroidMemory())
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid &droid)                                                     \
    : _id(droid.getId()), _energy(50),                                         \
    _attack(25), _toughness(15), _status(new std::string(*droid.getStatus())), \
    _battleData(new DroidMemory())
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (_status) delete _status;
    if (_battleData) delete _battleData;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

// --------------------------- Getters & Setters ---------------------------- //

std::string Droid::getId()
{
    return _id;
}

size_t Droid::getEnergy()
{
    return _energy;
}

size_t Droid::getAttack()
{
    return _attack;
}

size_t Droid::getToughness()
{
    return _toughness;
}

std::string *Droid::getStatus()
{
    return _status;
}

DroidMemory *Droid::getBattleData()
{
    return _battleData;
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t energy)
{
    _energy = energy;
}

void Droid::setStatus(std::string *status)
{
    _status = status;
}

void Droid::setBattleData(DroidMemory *droidMemory)
{
    _battleData = droidMemory;
}

// --------------------------- Operator Methods ----------------------------- //

Droid &Droid::operator=(Droid &droid)
{
    _id = droid.getId();
    if (_status) delete _status;
    _status = new (std::string)(*droid.getStatus());
    if (_battleData) delete _battleData;
    _battleData = new (DroidMemory)(*droid.getBattleData());

    return *this;
}

bool Droid::operator==(Droid &droid)
{
    return (_status == droid.getStatus());
}

bool Droid::operator!=(Droid &droid)
{
    return (_status != droid.getStatus());
}

Droid &Droid::operator<<(Droid &droid)
{
    const size_t MAX = 100;
    size_t difference;
    size_t energy;

    if (droid.getEnergy() == 0 || _energy == MAX) return *this;
    energy = droid.getEnergy();
    difference = MAX - _energy;
    if (difference > energy) {
        difference = energy;
    }
    this->setEnergy(_energy + difference);
    droid.setEnergy(energy  - difference);
    return *this;
}

Droid &Droid::operator<<(size_t &energy)
{
    const size_t MAX = 100;
    size_t difference;

    if (energy == 0 || _energy == MAX) return *this;
    difference = MAX - _energy;
    if (difference > energy) {
        difference = energy;
    }
    this->setEnergy(_energy + difference);
    energy -= difference;
    return *this;

}

bool Droid::operator()(std::string *task, size_t expCost)
{
    if (_energy <= 10) {
        _energy = 0;
        _status = new std::string("Battery Low");
    } else if (_battleData->getExp() >= expCost) {
        this->setEnergy(this->getEnergy() - 10);
        _battleData->setExp(_battleData->getExp() + (expCost / 2));
        _status = new std::string(*task + " - Completed!");
        return (true);
    } else {
        this->setEnergy(this->getEnergy() - 10);
        _battleData->setExp(_battleData->getExp() + expCost);
        _status = new std::string(*task + " - Failed!");
    }
    return (false);
}

// -------------------------------- Extern ---------------------------------- //

std::ostream &operator<<(std::ostream &os, Droid &droid)
{
    os << "Droid '" << droid.getId()
        << "', " << *droid.getStatus()
        << ", " << droid.getEnergy();
    return os;
}
