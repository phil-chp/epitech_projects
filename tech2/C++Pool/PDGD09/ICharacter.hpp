/*
** EPITECH PROJECT, 2022
** PDG-D9 (Workspace)
** File description:
** ICharacter
*/

#pragma once

#include <iostream>

class ICharacter {
    public:
        ICharacter() = default;
        virtual ~ICharacter() = default;

        virtual const std::string &getName()  const = 0;
        virtual int                getPower() const = 0;
        virtual int                getHp()    const = 0;

        virtual bool technique(int powerCost, const std::string &message) = 0;
        virtual int  attack() =  0;
        virtual int  special() = 0;
        virtual void rest() =    0;
        virtual void damage(int damage) = 0;
};
