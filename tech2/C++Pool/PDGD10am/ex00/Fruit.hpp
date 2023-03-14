/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** Fruit
*/

#pragma once

#include <iostream>

class Fruit {
    public:
        Fruit(std::string name, int vitamins);
        ~Fruit();

        const std::string getName() const;
        int getVitamins() const;

    private:
        const std::string _name;
        int _vitamins;
};
