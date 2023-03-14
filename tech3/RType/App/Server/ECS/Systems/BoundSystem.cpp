/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** BoundSystem
*/

#include "ECS/Systems/BoundSystem.hpp"

void ecs::BoundSystem::update(::engine::PollEvent &event) const
{
    for (ecs::Entity const &entity : this->entities) {
        Bound &bound         = Coordinator::getInstance().getComponent<Bound>(entity);
        RigidBody &rigidBody = Coordinator::getInstance().getComponent<RigidBody>(entity);
        Transform &trans     = Coordinator::getInstance().getComponent<Transform>(entity);

        if (trans.position.x < bound.x) {
            trans.position.x = bound.x;
            rigidBody.velocity.x = 0;
            rigidBody.acceleration.x = 0;
        }
        if (trans.position.x > bound.x + bound.width) {
            trans.position.x = bound.x + bound.width;
            rigidBody.velocity.x = 0;
            rigidBody.acceleration.x = 0;
        }
        if (trans.position.y < bound.y) {
            trans.position.y = bound.y;
            rigidBody.velocity.y = 0;
            rigidBody.acceleration.y = 0;
        }
        if (trans.position.y > bound.y + bound.height) {
            trans.position.y = bound.y + bound.height;
            rigidBody.velocity.y = 0;
            rigidBody.acceleration.y = 0;
        }
    }
}
