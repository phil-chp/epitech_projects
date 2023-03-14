/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Plane
*/

#include "Plane.hpp"

void rl::Plane::draw() const                                                  // Draw Plane
{
    ::DrawPlane(this->centerPos, this->size, this->color);
}
