/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Bilboard
*/

#include "Lib/Raylib/rl-cpp/Bilboard.hpp"

void rl::Billboard::draw(Camera const &camera) const;
{
    ::DrawBillboard(camera, this->texture, this->position, this->size, this->tint);
}
