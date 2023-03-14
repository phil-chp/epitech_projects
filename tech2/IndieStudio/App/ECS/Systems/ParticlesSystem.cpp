/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ParticlesSystem
*/

#include "ParticlesSystem.hpp"

void ecs::ParticlesSystem::update(float dt) const
{
    (void)dt;
    std::vector<Entity> toRemove;

    for (ecs::Entity const &entity : this->entities) {
        Particles &particles = ecs::Coordinator::getInstance().getComponent<Particles>(entity);
        if (!particles.started) {
            // particles.amp.debug();
            particles.explo.start(
                particles.amp
            );
            particles.started = true;
        } else if (particles.done) {
            toRemove.push_back(entity);
        } else {
            if (particles.explo.compute(rl::Window::getInstance().getCameraPosition())) {
                particles.done = true;
            }
        }
    }

    for (ecs::Entity entity : toRemove) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}
