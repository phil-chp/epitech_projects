/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ParticlesSystem
*/

#include "ECS/Systems/ParticlesSystem.hpp"
#include "Utils/Vector2.hpp"
#include "GameEngine/LinkerEntities.hpp"


void ecs::ParticlesSystem::update(::engine::PollEvent &event) const
{
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {

        RLParticles &particles = ecs::Coordinator::getInstance().getComponent<RLParticles>(entity);
        particles.update(entity, event.dt);
        for (auto &particle : particles._particles) {
            particle.draw();
        }

        if (particles._particles.size() <= 0) {
            toRm.push_back(entity);
        }
    }
    for (ecs::Entity &entity : toRm) {
        // ecs::Coordinator::getInstance().destroyEntity(entity);
        engine::LinkerEntities::getInstance().removeEntity(entity);
    }
}
