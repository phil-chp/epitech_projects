/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ShaderSystem
*/


#include "ECS/Systems/ShaderSystem.hpp"
#include "ECS/Components/RLShader.hpp"

void ecs::ShaderSystem::update(::engine::PollEvent &event) const {
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        RLShader &shader = ecs::Coordinator::getInstance().getComponent<RLShader>(entity);
        shader.update(entity, event.dt);
        shader.draw();


    }

    // for (ecs::Entity const &entity : toRm) {

    // }
}
