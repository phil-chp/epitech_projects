/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Bilboard
*/

#include "Bilboard.hpp"

void rl::Billboard::draw(Camera const &camera) const;
{
    ::DrawBillboard(camera, this->texture, this->position, this->size, this->tint);
}