/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** HomingSystem
*/

#include "HomingSystem.hpp"


void ecs::HomingSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Homing &homing    = ecs::Coordinator::getInstance().getComponent<Homing>(entity);
        Transform3D &target = ecs::Coordinator::getInstance().getComponent<Transform3D>(homing.at);
        Transform3D &trans  = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);
        RigidBody &body   = ecs::Coordinator::getInstance().getComponent<RigidBody>(entity);

        if (homing.activ) {
            rl::Vector3 path(std::move(trans.position.distance(target.position)));
            body.acceleration *= 0;
            body.acceleration += path;
        } else if (rand() %20 == 1) {
            homing.activ = true;
        }
    }
}
