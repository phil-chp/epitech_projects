/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BulletSystem
*/




#include "ECS/Systems/BulletSystem.hpp"


void ecs::BulletSystem::update(::engine::PollEvent &event) const
{
    for (ecs::Entity const &entity : this->entities) {
        ecs::Bullet &bullet = ecs::Coordinator::getInstance().getComponent<ecs::Bullet>(entity);
        bullet.update(entity, event);
    }
}
