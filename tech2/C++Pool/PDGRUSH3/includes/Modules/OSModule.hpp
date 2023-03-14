/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** OSModule
*/

#ifndef OSMODULE_HPP_
#define OSMODULE_HPP_

#include "Configurable.hpp"

typedef struct OS {
    std::string _kernel;
    std::string _version;
} OS;

class OSModule
        : public Configurable<OS>
{
    public:
        OSModule();
        ~OSModule();
        void refresh();
};

#endif /* !OSMODULE_HPP_ */
