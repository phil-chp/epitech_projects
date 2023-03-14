/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderButtonWidgetSystem.hpp"

void ecs::RenderButtonWidgetSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::DrawableButtonWidget &drawable = ecs::Coordinator::getInstance().getComponent<DrawableButtonWidget>(entity);
        ecs::Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);
        ecs::ButtonWidget &widget = ecs::Coordinator::getInstance().getComponent<ButtonWidget>(entity);

        drawable.draw(widget, trans.position, trans.scale);
    }
}
