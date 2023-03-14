/*
** EPITECH PROJECT, 2022
** RType
** File description:
** DrawTextSystem
*/

#include "ECS/Systems/DrawTextSystem.hpp"
#include "GameEngine/LinkerEntities.hpp"
#include "Utils/Vector2.hpp"

void ecs::DrawTextSystem::update(::engine::PollEvent &event) const
{
    (void)event;
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        RLText &drawable = ecs::Coordinator::getInstance().getComponent<RLText>(entity);

        ::game::Vector2 pos(drawable._text.position.x, drawable._text.position.y);
        drawable.draw(pos);
        if (drawable.dead) {
            toRm.push_back(entity);
        }
    }
    for (ecs::Entity entity : toRm) {
        // ecs::Coordinator::getInstance().destroyEntity(entity);
        engine::LinkerEntities::getInstance().removeEntity(entity);
    }
}
