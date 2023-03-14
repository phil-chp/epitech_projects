/*
** EPITECH PROJECT, 2022
** PDG-D7-AM (Workspace)
** File description:
** Borg
*/

#include "Borg.hpp"

Borg::Ship::Ship(int frequency, int repair) : _weaponFrequency(frequency),   \
    _repair(repair)
{
    _side = 300;
    _maxWarp = 9;
    _core = nullptr;
    _home = UNICOMPLEX;
    _location = _home;
    _shield = 100;
    // _weaponFrequency = frequency;
    // _repair = repair;

    std::cout << "We are the Borgs. Lower your shields and surrender"
        << " yourselves unconditionally.\n"
        << "Your biological characteristics and technologies will"
        << " be assimilated.\nResistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

void Borg::Ship::checkCore()
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();
    std::string status(reactor->isStable()
        ? "Everything is in order."
        : "Critical failure imminent.");

    std::cout << status << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (warp <= _maxWarp && d != _location && reactor->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (d != _location && reactor->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move(int warp)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (warp <= _maxWarp && _home != _location && reactor->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Borg::Ship::move()
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (_home != _location && reactor->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Borg::Ship::getShield()
{
    return _shield;
}

void Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return _weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    _weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return _repair;
}

void Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - _weaponFrequency);
    std::cout << "Firing on target with " << _weaponFrequency
        << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << _weaponFrequency
        << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    if (_repair > 0) {
        std::cout << "Begin shield re - initialisation ...";
        _repair -= 1;
        _shield = 100;
        std::cout << " Done . Awaiting further instructions." << std::endl;
    } else {
        std::cout << "Energy cells depleted, shield weakening." << std::endl;
    }
}
