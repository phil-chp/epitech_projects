/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Enchanter
*/

#pragma once

#include <iostream>
#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();

        virtual int  attack()  override;
        virtual int  special() override;
        virtual void rest()    override;
};
