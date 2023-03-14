/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderSettingsSystem.hpp"

void ecs::RenderSettingsSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::DrawableSettingsControl &drawable = ecs::Coordinator::getInstance().getComponent<DrawableSettingsControl>(entity);
        ecs::Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);
        ecs::ControlWidget &widget = ecs::Coordinator::getInstance().getComponent<ControlWidget>(entity);

        drawable.draw(widget, trans.position, trans.scale);
    }
}
