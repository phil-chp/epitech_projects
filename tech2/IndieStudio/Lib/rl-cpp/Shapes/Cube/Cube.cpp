/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Cube
*/

#include "Cube.hpp"

void rl::Cube::draw() const                                                  // Draw cube
{
    ::DrawCubeV(position, size, color);
}

void rl::Cube::drawWires()                                             // Draw cube wires
{
    ::DrawCubeWiresV(position, size, RL_BLACK);
}

void rl::Cube::drawTexture(Texture2D const &texture)                          // Draw cube textured
{
    ::DrawCubeTexture(texture, position, size.x, size.y, size.z, color);
}

void rl::Cube::drawTextureRec(Texture2D const &texture, Rectangle const &source)     // Draw cube with a region of a texture
{
    ::DrawCubeTextureRec(texture, source, position, size.x, size.y, size.z, color);
}

