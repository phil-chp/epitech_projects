/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** PartRenderSystem
*/

#include "PartRenderSystem.hpp"

void ecs::PartRenderSystem::update(float dt) const
{
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Particles &particles = ecs::Coordinator::getInstance().getComponent<Particles>(entity);

        particles.explo.draw();
    }
}
