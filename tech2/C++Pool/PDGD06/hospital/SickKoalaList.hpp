/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** SickKoalaList
*/

#pragma once

#include <iostream>
#include <list>
#include "SickKoala.hpp"

class SickKoalaList {
    public:
        SickKoalaList(const SickKoala *patient);
        ~SickKoalaList(void);
        bool isEnd(void);
        void append(SickKoalaList *list);
        SickKoala *getFromName(const std::string name);
        SickKoalaList *remove(SickKoalaList *list);
        SickKoalaList *removeFromName(const std::string name);
        SickKoala *getContent(void);
        SickKoalaList *getNext(void);

    private:
        std::list<SickKoala> _patients;
};
