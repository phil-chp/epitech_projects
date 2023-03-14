/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** Peasant
*/

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();

        const std::string &getName()  const;
        int                getPower() const;
        int                getHp()    const;

        void setHp(int hp);

        bool technique(int powerCost, const std::string &message);
        virtual int  attack();
        virtual int  special();
        virtual void rest();
        void damage(int damage);

    private:
        const std::string _name;
        int _power;
        int _hp;
};
