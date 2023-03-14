/*
** EPITECH PROJECT, 2022
** PDG-D7-AM (Workspace)
** File description:
** Federation
*/

#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name,   \
                                    short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _core = nullptr;
    _captain = NULL;
    _home = EARTH;
    _location = _home;
    _shield = 100;
    _photonTorpedo = torpedo;

    std::cout << "The ship USS " << _name << " has been finished.\n"
        << "It is " << _length << " m in length and "
        << _width <<" m in width.\n" << "It can go to Warp "
        << _maxWarp << "!\n";
    if (_photonTorpedo != 0) {
        std::cout << "Weapons are set: "
            << _photonTorpedo << " torpedoes ready.\n";
    }
    std::cout << std::flush;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();
    std::string status(
        reactor->isStable() ? "stable": "unstable"
    );

    std::cout << "USS " << _name
        << ": The core is " << status << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    _captain = captain;

    std::cout << _captain->getName()
        << ": I'm glad to be the captain of the USS "
        << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (warp <= _maxWarp && d != _location && reactor->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (d != _location && reactor->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (warp <= _maxWarp && _home != _location && reactor->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Starfleet::Ship::move()
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (_home != _location && reactor->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{

    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo >= 1) {
        _photonTorpedo -= 1;
        std::cout << _name << ": Firing on target. "
            << _photonTorpedo << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - 50);
    } else {
        std::cout << _name << ": No enough torpedoes to fire, "
            << _captain->getName() << "!" << std::endl;
    }
    if (_photonTorpedo == 0) {
        std::cout << _name << ": No more torpedo to fire, "
            << _captain->getName() << "!" << std::endl;
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo >= torpedoes) {
        _photonTorpedo -= torpedoes;
        std::cout << _name << ": Firing on target. "
            << _photonTorpedo << " torpedoes remaining.\n";
        target->setShield(target->getShield() - 50 * torpedoes);
    } else {
        std::cout << _name << ": No enough torpedoes to fire, "
            << _captain->getName() << "!\n";
    }
    // TODO: check for _photonTorpedo >= torpedoes too ?
    // To prevent double messages.
    if (_photonTorpedo == 0) {
        std::cout << _name << ": No more torpedo to fire, "
            << _captain->getName() << "!\n";
    }
    std::cout << std::flush;
}

// -------------------------------------------------------------------------- //

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _core = nullptr;
    _home = VULCAN;
    _location = _home;

    std::cout << "The independent ship " << _name
        << " just finished its construction.\n" << "It is " << _length
        << " m in length and " << _width << " m in width." << std::endl;

}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();
    std::string status(
        reactor->isStable() ? "stable": "unstable"
    );

    std::cout << _name
        << ": The core is " << status << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (warp <= _maxWarp && d != _location && reactor->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (d != _location && reactor->isStable() == true) {
        _location = d;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (warp <= _maxWarp && _home != _location && reactor->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

bool Federation::Ship::move()
{
    WarpSystem::QuantumReactor *reactor = _core->checkReactor();

    if (_home != _location && reactor->isStable() == true) {
        _location = _home;
        return (true);
    }
    return (false);
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return _core;
}

// -------------------------------------------------------------------------- //


Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

// -------------------------------------------------------------------------- //

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;

    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;

}

Federation::Starfleet::Ensign::~Ensign()
{
}
