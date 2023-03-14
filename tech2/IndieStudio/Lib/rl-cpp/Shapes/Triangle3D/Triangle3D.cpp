/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Triangle3D
*/

#include "Triangle3D.hpp"

void rl::Triangle3D::draw() const                                                  // Draw Triangle3D
{
    ::DrawTriangle3D(this->v1, this->v2, this->v3, this->color);
}

void rl::Triangle3D::drawStrip(Vector2 *points, int pointsCount)                   // Draw Triangle3D strip
{
    ::DrawTriangleStrip(points, pointsCount, this->color);
}
