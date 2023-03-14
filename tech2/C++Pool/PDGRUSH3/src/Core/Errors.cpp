/*
** EPITECH PROJECT, 2022
** C POOL, rush-03-myGKrellm
** authored by:
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
**      Vitali DROUJKO <vitali.droujko@epitech.eu>
**      Mateo DEROCHE <mateo.deroche.epitech.eu>
** File description:
** TODO
*/

#include "Errors.hpp"

ErrorManager::ErrorManager(std::string const &message, std::string const &component) \
    : _message(message), _component(component)
{
    // do nothing
}

const char* ErrorManager::what() const throw()
{
    return _message.c_str();
}

std::string const &ErrorManager::getComponent() const
{
    return _component;
}

ArgumentError::ArgumentError(std::string const &message, std::string const &component) \
    : ErrorManager(message, component)
{
    // do nothing
}

ConfigError::ConfigError(std::string const &message, std::string const &component) \
    : ErrorManager(message, component)
{
    // do nothing
}
