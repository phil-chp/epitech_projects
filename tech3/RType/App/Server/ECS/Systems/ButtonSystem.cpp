/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ButtonSystem
*/

#include "ECS/Systems/ButtonSystem.hpp"
#include "GameEngine/LinkerEntities.hpp"

void ecs::ButtonSystem::update(::engine::PollEvent &event) const
{
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        Button &button         = Coordinator::getInstance().getComponent<Button>(entity);
        // RigidBody &rigidBody   = Coordinator::getInstance().getComponent<RigidBody>(entity);
        // Transform &trans       = Coordinator::getInstance().getComponent<Transform>(entity);
        if (button.dead) {
            toRm.push_back(entity);
        }
        // if (button.isClic) {
        //     //change anim
        //     button.click();
        //     button.isClic = false;
        // }
        // if (button.isHover) {
        //     button.hover();
        // }
    }
    for (ecs::Entity entity : toRm) {
        engine::LinkerEntities::getInstance().removeEntity(entity);
    }
}
