/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Point3D
*/

#include "Lib/Raylib/rl-cpp/Shapes/Point3D/Point3D.hpp"

void rl::Point3D::draw() const                                                  // Draw Point3D
{
    ::DrawPoint3D(this->position, this->color);
}
