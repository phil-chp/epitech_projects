/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderMapWidgetSystem.hpp"

void ecs::RenderMapWidgetSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::DrawableMapWidget &drawable = ecs::Coordinator::getInstance().getComponent<DrawableMapWidget>(entity);
        ecs::Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);
        ecs::MapWidget &widget = ecs::Coordinator::getInstance().getComponent<MapWidget>(entity);

        drawable.draw(widget, trans.position, trans.scale);
    }
}
