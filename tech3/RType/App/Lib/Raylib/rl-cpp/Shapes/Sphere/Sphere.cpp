/*RED
** EPITECH PROJECT, 2022
** RType
** File description:
** Sphere
*/

#include "Lib/Raylib/rl-cpp/Shapes/Sphere/Sphere.hpp"

void rl::Sphere::draw() const                                                  // Draw Sphere
{
    ::DrawSphere(position, radius, color);
}

void rl::Sphere::drawWires(int rings, int slices) const                                         // Draw Sphere wires
{
    ::DrawSphereWires(position, radius, rings, slices, RL_BLACK);
}

void rl::Sphere::drawEx(int rings, int slices)                           // Draw sphere with extended parameters
{
    ::DrawSphereEx(position, radius, rings, slices, color);
}
