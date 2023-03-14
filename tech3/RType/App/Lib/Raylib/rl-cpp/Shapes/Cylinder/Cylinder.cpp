/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Cylinder
*/

#include "Lib/Raylib/rl-cpp/Shapes/Cylinder/Cylinder.hpp"

void rl::Cylinder::draw() const                                                                                        // Draw Cylinder
{
    ::DrawCylinder(this->position, this->radiusTop, this->radiusBottom, this->height, this->slices, this->color);
}

void rl::Cylinder::drawEx(Vector3 const &startPos, Vector3 const &endPos, float startRadius, float endRadius, int sides)       // Draw a cylinder with base at startPos and top at endPos
{
    ::DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, this->color);
}

void rl::Cylinder::drawWires()                                                                                   // Draw a cylinder/cone wires
{
    ::DrawCylinderWires(this->position, this->radiusTop, this->radiusBottom, this->height, this->slices, RL_BLACK);
}

void rl::Cylinder::drawWiresEx(Vector3 const &startPos, Vector3 const &endPos, float startRadius, float endRadius, int sides)  // Draw a cylinder wires with base at startPos and top at endPos
{
    ::DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, this->color);
}
