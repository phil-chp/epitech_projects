/*
** EPITECH PROJECT, 2022
** PDG-D8 (Workspace)
** File description:
** Droid
*/

#pragma once

#include <iostream>
#include <cstdlib>

class Droid {
    public:
        Droid(std::string id = "");
        Droid(Droid &droid);
        ~Droid();

        std::string  getId();
        size_t       getEnergy();
        size_t       getAttack();
        size_t       getToughness();
        std::string *getStatus();

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);

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
};

std::ostream &operator<<(std::ostream &os, Droid &droid);
