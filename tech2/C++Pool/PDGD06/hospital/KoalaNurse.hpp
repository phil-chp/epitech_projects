/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** KoalaNurse
*/

#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>
#include "SickKoala.hpp"

class KoalaNurse {
    public:
        KoalaNurse(const int id);
        ~KoalaNurse(void);
        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string filename);
        void timeCheck(void);
        int getID(void);

    private:
        int _id;
        bool _working;
};
