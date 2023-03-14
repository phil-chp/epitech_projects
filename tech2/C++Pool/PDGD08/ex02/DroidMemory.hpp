/*
** EPITECH PROJECT, 2022
** PDG-D8 (Workspace)
** File description:
** DroidMemory
*/

#pragma once

#include <iostream>
#include <cstddef>

class DroidMemory {
    public:
        DroidMemory();
        // DroidMemory(DroidMemory &droidMemory);
        ~DroidMemory();

        size_t getFingerprint();
        size_t getExp();

        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);

        // DroidMemory &operator=(DroidMemory &droidMemory);
        DroidMemory &operator<<(DroidMemory &droidMemory);
        DroidMemory &operator>>(DroidMemory &droidMemory);
        DroidMemory &operator+=(DroidMemory &droidMemory);
        DroidMemory &operator+=(size_t exp);
        DroidMemory &operator+(DroidMemory &droidMemory);
        DroidMemory &operator+(const size_t exp);
        bool         operator==(DroidMemory &droidMemory);
        bool         operator!=(DroidMemory &droidMemory);
        bool         operator<(DroidMemory &droidMemory);
        bool         operator<=(DroidMemory &droidMemory);
        bool         operator>(DroidMemory &droidMemory);
        bool         operator>=(DroidMemory &droidMemory);

    private:
        size_t _exp;
        size_t _fingerprint;
};

std::ostream &operator<<(std::ostream &os, DroidMemory &droidMemory);
