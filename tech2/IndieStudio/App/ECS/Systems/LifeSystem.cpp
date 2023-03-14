/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** LifeSystem
*/

#include "LifeSystem.hpp"


void ecs::LifeSystem::update(float dt) const {
    (void)dt;
    std::vector<Entity> toRemove;
    for (ecs::Entity const &entity : this->entities) {
        Alive &alive = ecs::Coordinator::getInstance().getComponent<Alive>(entity);

        if (alive.dead) {
            toRemove.push_back(entity);
        }
        if (alive.health <= 0) {
            alive.dead = true;
        }
    }

    for (ecs::Entity entity : toRemove) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}
