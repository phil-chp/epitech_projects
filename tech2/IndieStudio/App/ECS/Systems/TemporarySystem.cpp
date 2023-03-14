/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** TemporarySystem
*/

#include "TemporarySystem.hpp"


void ecs::TemporarySystem::update(float dt) const {
    (void)dt;
    std::vector<Entity> toRemove;
    for (ecs::Entity const &entity : this->entities) {
        Temporary &temp = ecs::Coordinator::getInstance().getComponent<Temporary>(entity);

        if (temp.done) {
            toRemove.push_back(entity);
        } else {
            temp.delay -= dt;
            if (temp.delay <= 0) {
                temp.done = true;
            }
        }
    }

    for (ecs::Entity entity : toRemove) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}
