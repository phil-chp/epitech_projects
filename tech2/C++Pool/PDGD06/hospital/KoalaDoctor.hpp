/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** KoalaDoctor
*/

#pragma once

#include <iostream>
#include <fstream>
#include "SickKoala.hpp"

class KoalaDoctor {
    public:
        KoalaDoctor(const std::string name);
        ~KoalaDoctor(void);
        void diagnose(SickKoala *patient);
        void timeCheck(void);
        std::string getName(void);

    private:
        std::string _name;
        bool _working;
};
