/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Grid
*/

#include "Lib/Raylib/rl-cpp/Shapes/Grid/Grid.hpp"

void rl::Grid::draw() const                                                  // Draw Grid
{
    ::DrawGrid(slices, spacing);
}
