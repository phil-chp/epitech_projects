/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderTextureWidgetSystem.hpp"

void ecs::RenderTextureWidgetSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::TextureWidget &drawable = ecs::Coordinator::getInstance().getComponent<TextureWidget>(entity);
        ecs::Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);

        drawable.texture.drawEx(trans.position, 0.0f, 1.0f, rl::RL_WHITE);
    }
}
