/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Priest
*/

#pragma once

#include <iostream>
#include "Enchanter.hpp"
#include "Peasant.hpp"

class Priest : public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        virtual void rest() override;
};
