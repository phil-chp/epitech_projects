/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderSystem.hpp"


void ecs::RenderSystem::update(float dt) const {
    // TODO: unused parameter ?
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Drawable &drawable = ecs::Coordinator::getInstance().getComponent<Drawable>(entity);
        Transform3D &trans = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);

        drawable.draw(trans.position, trans.scale);
    }
}
