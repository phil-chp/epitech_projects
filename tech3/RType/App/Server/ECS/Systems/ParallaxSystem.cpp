/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ParallaxSystem
*/

#include "ParallaxSystem.hpp"

void ecs::ParallaxSystem::update(::engine::PollEvent &event) const {
    for (ecs::Entity const &entity : this->entities) {
        int i = 0;
        ecs::Parallax &parallax = ecs::Coordinator::getInstance().getComponent<Parallax>(entity);
        for (ecs::Entity ent : parallax.layers) {
            ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(ent);
            if (transform.position.x < parallax.finish) {
                transform.position.x += parallax.size;
                // std::cout << "layer : " << i << " finshed\n\treseted to " << transform.position.x << std::endl;
            }
            i++;
        }
    }
}
