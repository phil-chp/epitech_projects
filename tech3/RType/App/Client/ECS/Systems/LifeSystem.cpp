/*
** EPITECH PROJECT, 2022
** RType
** File description:
** LifeSystem
*/

#include "ECS/Systems/LifeSystem.hpp"
#include "GameEngine/LinkerEntities.hpp"

void ecs::LifeSystem::update(::engine::PollEvent &event) const {
    (void)event;
    std::vector<ecs::Entity> toRemove;
    for (ecs::Entity const &entity : this->entities) {
        ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(entity);

        if (alive.dead) {
            toRemove.push_back(entity);
        }
        if (alive.hp <= 0) {
            alive.dead = true;
        }
    }

    for (ecs::Entity entity : toRemove) {
        // std::cout << "remover" << std::endl;
        // ecs::Coordinator::getInstance().destroyEntity(entity);
        engine::LinkerEntities::getInstance().removeEntity(entity);
    }
}
