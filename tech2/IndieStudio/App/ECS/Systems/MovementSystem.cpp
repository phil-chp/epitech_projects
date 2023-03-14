/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** MovementSystem
*/

#include "MovementSystem.hpp"


void ecs::MovementSystem::update(float dt) const {
    for (ecs::Entity const &entity : this->entities) {
        RigidBody &rigidBody = ecs::Coordinator::getInstance().getComponent<RigidBody>(entity);
        Transform3D &transform = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);
        // Scalable &scaling    = ecs::Coordinator::getInstance().getComponent<Scalable>(entity);

        transform.position += rigidBody.velocity * dt;

        // transform.scale += scaling.scale;
        // if (abs(transform.scale.x) > 5 || abs(transform.scale.y) > 5 || abs(transform.scale.z) > 5) {
        //     scaling.scale *= -1;
        // }
    }
}
