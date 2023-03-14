/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SpawnSystem
*/

#include "ECS/Systems/SpawnSystem.hpp"
#include "GameEngine/LinkerEntities.hpp"


void ecs::SpawnSystem::update(::engine::PollEvent &event) const {
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        bool spawned = false;
        Spawn &spawn = ecs::Coordinator::getInstance().getComponent<Spawn>(entity);
        if (spawn.repeat <= 0) {
            toRm.push_back(entity);
        }
        if (spawn.timed) {
            Temporary &temp = ecs::Coordinator::getInstance().getComponent<Temporary>(entity);
            if (temp.done) {
                // temp.done = false;
                // temp.delay = spawn.
                spawn.spawn(entity);
                spawned = true;
            }
        }
        if (!spawned && spawn.lifed) {
            // Alive &alive = ecs::Coordinator::getInstance().getComponent<Alive>(entity);
            // if (alive.dead) {
            //     spawn.spawn(entity);
            //     spawn.repeat -= 1;
            //     spawned = true;
            // }
        }
    }
    for (ecs::Entity const &entity : toRm) {
        // ecs::Coordinator::getInstance().destroyEntity(entity);
        engine::LinkerEntities::getInstance().removeEntity(entity);
    }
}
