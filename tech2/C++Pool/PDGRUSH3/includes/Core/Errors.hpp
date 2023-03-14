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

#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <string>

class ErrorManager : public std::exception {
    private:
        std::string _message;
        std::string _component;
    public:
        ErrorManager(std::string const &message, std::string const &component = "Unknown");
        std::string const &getComponent() const;
        const char *what() const throw();
};

class ArgumentError : public ErrorManager
{
    public:
        ArgumentError(std::string const &message, std::string const &component = "Unknown");
};

class ConfigError : public ErrorManager
{
    public:
        ConfigError(std::string const &message, std::string const &component = "Unknown");
};

#endif /* !ERRORS_HPP */
