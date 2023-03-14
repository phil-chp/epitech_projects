/*
** EPITECH PROJECT, 2022
** PDG-D10-AM (Workspace)
** File description:
** FruitNode
*/

#pragma once

#include "Fruit.hpp"

struct FruitNode {
    Fruit *fruit;
    FruitNode *next;
};
