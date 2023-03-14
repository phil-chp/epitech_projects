/*
** EPITECH PROJECT, 2022
** PDG-D8 (Workspace)
** File description:
** Droid
*/

#pragma once

#include <iostream>
#include <cstdlib>
#include "DroidMemory.hpp"

class Droid {
    public:
        Droid(std::string id);
        Droid(Droid &droid);
        ~Droid();

        std::string  getId();
        size_t       getEnergy();
        size_t       getAttack();
        size_t       getToughness();
        std::string *getStatus();
        DroidMemory *getBattleData();

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);
        void setBattleData(DroidMemory *droidMemory);

        Droid &operator=(Droid &droid);
        bool   operator==(Droid& droid);
        bool   operator!=(Droid& droid);
        Droid &operator<<(Droid& droid);
        Droid &operator<<(size_t &energy);

    private:
        std::string  _id;
        size_t       _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string *_status;
        DroidMemory *_battleData;
};

std::ostream &operator<<(std::ostream &os, Droid &droid);
