/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Paladin
*/

#pragma once

#include <iostream>
#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : public Knight, public Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int  attack()  override;
        int  special() override;
        void rest()    override;
};
