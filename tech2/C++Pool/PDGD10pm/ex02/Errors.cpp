/*
** EPITECH PROJECT, 2022
** PDG-D10-PM (Workspace)
** File description:
** Errors
*/

#include "Errors.hpp"

// ------------------------------ Subroutines ------------------------------- //

NasaError::NasaError(std::string const &message, std::string const &component)
    : _message(message), _component(component)
{
}

MissionCriticalError::MissionCriticalError(const std::string &message, const std::string &component)
    : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(const std::string &message, const std::string &component)
    : NasaError(message, component)
{
}

UserError::UserError(const std::string &message, const std::string &component)
    : NasaError(message, component)
{
}

CommunicationError::CommunicationError(const std::string &message)
    : NasaError(message, "CommunicationDevice")
{
}

// -------------------------------- Methods --------------------------------- //

const std::string &NasaError::getComponent() const
{
        return _component;
}

const char *NasaError::what() const throw()
{
    return _message.c_str();
}
