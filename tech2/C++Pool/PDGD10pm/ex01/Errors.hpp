/*
** EPITECH PROJECT, 2022
** PDG-D10-PM (Workspace)
** File description:
** Errors
*/

#pragma once

#include <iostream>
#include <string>

class NasaError : public std::exception {
    public:
        NasaError(const std::string &message,            \
                const std::string &component = "Unknown");

        const std::string &getComponent() const;
        virtual const char *what() const throw();

    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public NasaError {
    public:
        MissionCriticalError(const std::string &message, \
                const std::string &component = "Unknown");
};

class LifeCriticalError : public NasaError {
    public:
        LifeCriticalError(const std::string &message,    \
                const std::string &component = "Unknown");
};

class UserError : public NasaError {
    public:
        UserError(const std::string &message,            \
                const std::string &component = "Unknown");
};

class CommunicationError : public NasaError {
    public:
        CommunicationError(const std::string &message,   \
                            const std::string &component);
};
