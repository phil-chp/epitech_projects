/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Plane
*/

#include "Lib/Raylib/rl-cpp/Shapes/Plane/Plane.hpp"

void rl::Plane::draw() const                                                  // Draw Plane
{
    ::DrawPlane(this->centerPos, this->size, this->color);
}
