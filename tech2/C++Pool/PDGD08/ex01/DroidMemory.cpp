/*
** EPITECH PROJECT, 2022
** PDG-D8 (Workspace)
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

// ------------------------------ Subroutines ------------------------------- //

DroidMemory::DroidMemory() : _exp(0), _fingerprint((size_t)random())
{
}

// DroidMemory::DroidMemory(DroidMemory &droidMemory)  /
//     : _exp(0), _fingerprint(droidMemory.getFingerprint())
// {
// }

DroidMemory::~DroidMemory()
{
}

// --------------------------- Getters & Setters ---------------------------- //

size_t DroidMemory::getFingerprint()
{
    return _fingerprint;
}

size_t DroidMemory::getExp()
{
    return _exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _fingerprint = fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

// DroidMemory &DroidMemory::operator=(DroidMemory &droidMemory)
// {
//     _exp = droidMemory.getExp();
//     _fingerprint = droidMemory.getFingerprint();
//     return *this;
// }

DroidMemory &DroidMemory::operator<<(DroidMemory &droidMemory)
{
    _exp += droidMemory.getExp();
    _fingerprint ^= droidMemory.getFingerprint();
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &droidMemory)
{
    droidMemory.setExp(droidMemory.getExp() + _exp);
    droidMemory.setFingerprint(droidMemory.getFingerprint() ^ _fingerprint);
    return droidMemory;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &droidMemory)
{
    _exp += droidMemory.getExp();
    _fingerprint ^= droidMemory.getFingerprint();
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint ^= exp;
    return *this;
}

DroidMemory &DroidMemory::operator+(const size_t exp)
{
    DroidMemory *droidMemory = new DroidMemory();
    droidMemory->_exp += exp;
    droidMemory->_fingerprint ^= exp;
    return *droidMemory;
}

// -------------------------------- Extern ---------------------------------- //

std::ostream &operator<<(std::ostream &os, DroidMemory &droidMemory)
{
    os << "DroidMemory '" << droidMemory.getFingerprint()
        << "', " << droidMemory.getExp();
    return os;
}
