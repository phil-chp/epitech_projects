/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Triangle3D
*/

#include "Lib/Raylib/rl-cpp/Shapes/Triangle3D/Triangle3D.hpp"

void rl::Triangle3D::draw() const                                                  // Draw Triangle3D
{
    ::DrawTriangle3D(this->v1, this->v2, this->v3, this->color);
}

void rl::Triangle3D::drawStrip(Vector2 *points, int pointsCount)                   // Draw Triangle3D strip
{
    ::DrawTriangleStrip(points, pointsCount, this->color);
}
