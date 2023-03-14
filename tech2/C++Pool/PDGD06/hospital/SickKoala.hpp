/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** SickKoala
*/

#pragma once

#include <iostream>
#include <cstring>

class SickKoala {
    public:
        SickKoala(const std::string name);
        ~SickKoala(void);
        void poke(void);
        bool takeDrug(std::string food);
        void overDrive(std::string message);
        std::string getName(void);

    private:
        std::string _name;
};
