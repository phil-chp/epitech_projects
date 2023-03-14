/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Line3D
*/

#include "Line3D.hpp"

void rl::Line3D::draw() const                                                  // Draw Line3D
{
    ::DrawLine3D(this->startPos, this->endPos, this->color);
}
