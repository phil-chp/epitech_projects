/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ScrollSystem
*/

#include "ECS/Systems/ScrollSystem.hpp"

void ecs::ScrollSystem::update(::engine::PollEvent &event) const {
    for (ecs::Entity const &entity : this->entities) {
        Scroll &scroll = ecs::Coordinator::getInstance().getComponent<Scroll>(entity);
        Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(entity);

        if (!scroll.pause) {
            transform.position.x += scroll.xVel * event.dt;
            transform.position.y += scroll.yVel * event.dt;
        }
    }
}
