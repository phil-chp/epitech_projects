/*
** EPITECH PROJECT, 2022
** RType
** File description:
** DrawSystem
*/

#include "ECS/Systems/DrawSystem.hpp"
#include "Utils/Vector2.hpp"

void ecs::DrawSystem::update(::engine::PollEvent &event) const
{
    (void)event;
    for (ecs::Entity const &entity : this->entities) {
        RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<RLDrawable>(entity);

        Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(entity);

        if (drawable.shadered == false) {
            drawable.drawRec(transform.position);
        }
    }
}
