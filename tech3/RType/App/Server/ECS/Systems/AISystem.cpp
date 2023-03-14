/*
** EPITECH PROJECT, 2022
** RType
** File description:
** AISystem
*/


#include "ECS/Systems/AISystem.hpp"

void ecs::AISystem::update(::engine::PollEvent &event) const
{
    for (ecs::Entity const &entity : this->entities) {
        ecs::AI &ai = Coordinator::getInstance().getComponent<ecs::AI>(entity);
        ai.lifeTime += event.dt;
        ai.move.updateMove(entity, event.dt);
        if (!ai.move.set) {
            // if (ai.move.type == ecs::AIMoveType::AIMOV_STRAIGHT) {
            //     ecs::RigidBody &body = Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
            //     body.velocity.x = ai.move.val.a;
            //     body.velocity.y = ai.move.val.b;
            // }
            ai.move.set = true;
        }
        if (!ai.shoot.set) {
            ecs::Shoot &shoot = Coordinator::getInstance().getComponent<ecs::Shoot>(entity);
            shoot.aimType     = ai.shoot.aimType;
            shoot.target      = ai.shoot.target;
            shoot.targetPoint = ai.shoot.targetPoint;
            ai.shoot.set      = true;
        }
    }
}
