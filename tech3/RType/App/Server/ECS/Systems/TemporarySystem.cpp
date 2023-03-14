/*
** EPITECH PROJECT, 2022
** RType
** File description:
** TemporarySystem
*/

#include "ECS/Systems/TemporarySystem.hpp"
#include "GameEngine/IBonus.hpp"
#include "GameEngine/GameEntities.hpp"
#include "GameEngine/LinkerEntities.hpp"


void ecs::TemporarySystem::update(::engine::PollEvent &event) const {
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        Temporary &temporary = ecs::Coordinator::getInstance().getComponent<Temporary>(entity);
        if (temporary.done) {
            if (temporary.isBonus) {
                engine::IBonus *bonus = static_cast<engine::IBonus *> (engine::GameEntities::getInstance().getEntity(entity).get());
                bonus->remove();
            }
            toRm.push_back(entity);
        } else if (temporary.delay <= 0) {
            temporary.done = true;
        } else {
            temporary.delay -= event.dt;
        }
    }
    for (ecs::Entity const &entity : toRm) {
        engine::LinkerEntities::getInstance().removeEntity(entity);

        // ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}
