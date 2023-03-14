/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** PhysicsSystem
*/

#include "PhysicsSystem.hpp"


void ecs::PhysicsSystem::update(float dt) const {
    for (ecs::Entity const &entity : this->entities) {
        RigidBody &rigidBody = ecs::Coordinator::getInstance().getComponent<RigidBody>(entity);
        // Transform3D &transform = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);
        Gravity &gravity     = ecs::Coordinator::getInstance().getComponent<Gravity>(entity);

        if (!rigidBody.movable) continue;

        // transform.rotation = rigidBody.velocity;
        rigidBody.velocity += rigidBody.acceleration * dt;
        rigidBody.acceleration += gravity.force * dt * rigidBody.mass;
        if (rigidBody.grounded) {
            // transform.position.y = transform.scale.y / 2;
            rigidBody.acceleration.y = 0;
            if (fabs(rigidBody.velocity.x) > 0.3) {
                rigidBody.acceleration.x = -rigidBody.mass * rigidBody.velocity.x;
            }else {
                rigidBody.velocity.x = 0;
                rigidBody.acceleration.x = 0;
            }
            if (fabs(rigidBody.velocity.z) > 0.3) {
                rigidBody.acceleration.z = -rigidBody.mass * rigidBody.velocity.z;
            }else {
                rigidBody.velocity.z = 0;
                rigidBody.acceleration.z = 0;
            }
            // rigidBody.acceleration.y = 0;
        } else {
            rigidBody.acceleration.x = 0;
            rigidBody.acceleration.z = 0;
        }
    }
}
