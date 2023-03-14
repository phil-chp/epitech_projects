/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderPlayerWidgetSystem.hpp"

void ecs::RenderPlayerWidgetSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::DrawablePlayerWidget &drawable = ecs::Coordinator::getInstance().getComponent<DrawablePlayerWidget>(entity);
        ecs::Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);
        ecs::PlayerWidget &widget = ecs::Coordinator::getInstance().getComponent<PlayerWidget>(entity);

        drawable.draw(widget, trans.position, trans.scale);
    }
}
