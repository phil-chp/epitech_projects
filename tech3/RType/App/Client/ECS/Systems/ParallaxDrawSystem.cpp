/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ParallaxDrawSystem
*/

#include "ECS/Systems/ParallaxDrawSystem.hpp"
#include "Utils/Vector2.hpp"
#include "ECS/Coordinator.hpp"

void ecs::ParallaxDrawSystem::update(::engine::PollEvent &event) const
{
    for (ecs::Entity const &entity : this->entities) {
        ecs::Parallax &parallax = ecs::Coordinator::getInstance().getComponent<Parallax>(entity);
        for (ecs::Entity layer : parallax.layers) {
            for (unsigned int i = 0; i < parallax.reps; ++i) {
                RLBackground &background = ecs::Coordinator::getInstance().getComponent<RLBackground>(layer);
                Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(layer);

                background.draw(game::Vector2(transform.position.x + i * parallax.size, transform.position.y));
            }
        }
    }
}
