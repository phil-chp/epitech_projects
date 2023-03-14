/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ParallaxRenderSystem
*/

#include "ParallaxRenderSystem.hpp"

void ecs::ParallaxRenderSystem::update(float dt) const
{
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::Parallax &parallax = ecs::Coordinator::getInstance().getComponent<Parallax>(entity);

        static rl::Texture background(rl::TextureType::TEXTURE_NEBULA);
        static rl::Texture smallStars(rl::TextureType::TEXTURE_BIG_STARS);
        static rl::Texture bigStars(rl::TextureType::TEXTURE_SMALL_STARS);

        if (parallax.scrollingBack <= -background.width * 2) parallax.scrollingBack = 0;
        if (parallax.scrollingMid  <= -smallStars.width * 2) parallax.scrollingMid  = 0;
        if (parallax.scrollingFore <= -bigStars.width * 2) parallax.scrollingFore = 0;

        background.drawEx(rl::Vector2(parallax.scrollingBack, 0), 0.0f, 2.0f);
        smallStars.drawEx(rl::Vector2(parallax.scrollingMid, 0), 0.0f, 1.0f);
        bigStars.drawEx(rl::Vector2(parallax.scrollingFore, 0), 0.0f, 2.0f);
	}
}
