/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Circle3D
*/

#include "Lib/Raylib/rl-cpp/Shapes/Circle3D/Circle3D.hpp"

void rl::Circle3D::draw() const                                                  // Draw Circle3D
{
    ::DrawCircle3D(this->center, this->radius, this->rotationAxis, this->rotationAngle, this->color);
}
