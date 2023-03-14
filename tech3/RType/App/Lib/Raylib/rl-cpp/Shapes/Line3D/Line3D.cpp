/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Line3D
*/

#include "Lib/Raylib/rl-cpp/Shapes/Line3D/Line3D.hpp"

void rl::Line3D::draw() const                                                  // Draw Line3D
{
    ::DrawLine3D(this->startPos, this->endPos, this->color);
}
