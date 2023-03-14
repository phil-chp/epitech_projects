/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** FruitBox
*/

#pragma once

#include <iostream>
#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();

        int nbFruits();
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head();

    private:
        int _size;
        FruitNode *_head;
};
