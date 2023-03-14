/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ParallaxSystem
*/

#include "ParallaxSystem.hpp"

void ecs::ParallaxSystem::update(float dt) const
{
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Parallax &parallax = ecs::Coordinator::getInstance().getComponent<Parallax>(entity);

        parallax.scrollingBack -= 0.1f;
        parallax.scrollingMid  -= 0.5f;
        parallax.scrollingFore -= 1.0f;
	}
}
