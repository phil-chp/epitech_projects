/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** LittleHand
*/

#pragma once

#include <iostream>
#include "Fruit.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "FruitBox.hpp"
#include "FruitNode.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();

        void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, \
                            FruitBox &bananas, FruitBox &limes);
};
