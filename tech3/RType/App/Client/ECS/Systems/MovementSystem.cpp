/*
** EPITECH PROJECT, 2022
** RType
** File description:
** MovementSystem
*/

#include "ECS/Systems/MovementSystem.hpp"

void ecs::MovementSystem::update(::engine::PollEvent &event) const {
    for (ecs::Entity const &entity : this->entities) {
        RigidBody &rigidBody = ecs::Coordinator::getInstance().getComponent<RigidBody>(entity);
        Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(entity);
        // Hitbox &hitbox = ecs::Coordinator::getInstance().getComponent<Hitbox>(entity);
        // Scalable &scaling    = ecs::Coordinator::getInstance().getComponent<Scalable>(entity);

        transform.position  += rigidBody.velocity * event.dt;
        rigidBody.velocity  += rigidBody.acceleration * event.dt;
        // std::cout << "moved " << entity << " to new surface {" << hitbox.bounds->pos.x << ", " << hitbox.bounds->pos.y << ", " << hitbox.bounds->val.a << ", " << hitbox.bounds->val.b << "}" << std::endl;


        // transform.scale += scaling.scale;
        // if (abs(transform.scale.x) > 5 || abs(transform.scale.y) > 5 || abs(transform.scale.z) > 5) {
        //     scaling.scale *= -1;
        // }
    }
}
