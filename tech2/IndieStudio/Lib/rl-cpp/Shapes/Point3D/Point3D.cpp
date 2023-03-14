/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Point3D
*/

#include "Point3D.hpp"

void rl::Point3D::draw() const                                                  // Draw Point3D
{
    ::DrawPoint3D(this->position, this->color);
}
