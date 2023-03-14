/*
** EPITECH PROJECT, 2022
** PDG-D7-AM (Workspace)
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return _coreReactor;
}

// -------------------------------------------------------------------------- //

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return _stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}
