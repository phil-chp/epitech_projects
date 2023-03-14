/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, \
                                FruitBox &bananas, FruitBox &limes)
{
    Fruit *fruit = unsorted.pickFruit();

    if (fruit == nullptr) return;
    if (fruit->getName() == "banana") {
        bananas.putFruit(dynamic_cast<Banana *>(fruit));
    } else if (fruit->getName() == "lemon") {
        lemons.putFruit(dynamic_cast<Lemon *>(fruit));
    } else if (fruit->getName() == "lime") {
        limes.putFruit(dynamic_cast<Lime *>(fruit));
    } else {
        unsorted.putFruit(fruit);
        if (unsorted.nbFruits() == 1) return;
    }
    sortFruitBox(unsorted, lemons, bananas, limes);
}
