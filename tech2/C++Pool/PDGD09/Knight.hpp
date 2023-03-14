/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Knight
*/

#pragma once

#include <iostream>
#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();

        virtual int  attack()  override;
        virtual int  special() override;
        virtual void rest()    override;
};
