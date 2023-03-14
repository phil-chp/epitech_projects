/*RED
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Sphere
*/

#include "Sphere.hpp"

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
