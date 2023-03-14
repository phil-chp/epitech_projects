/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ShootSystem
*/

#include "ECS/Systems/ShootSystem.hpp"

void ecs::ShootSystem::update(::engine::PollEvent &event) const {
    // std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        Shoot &shoot = ecs::Coordinator::getInstance().getComponent<Shoot>(entity);
        Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(entity);
        // shoot.update(entity, event);
        // for (ecs::Entity const &ent : shot) {
        //     Alive &life = ecs::Coordinator::getInstance().getComponent<Alive>(entity);
        //     if (life.dead) {
        //         toRm.push_back(ent);
        //     }
        if (shoot.shtType == ecs::ShootType::SHT_CONTROL) {
            Control &control = ecs::Coordinator::getInstance().getComponent<Control>(entity);
            if (((event.playerEvents[control.eventID].pressed & engine::SHOOT) == engine::SHOOT) && shoot.delay < 0) {
                if (shoot.aimType == ecs::AimType::AIM_STRAIGHT) {
                    shoot.shots.push_back(shoot.fire(transform.position, shoot.lvl, ::game::Vector2(transform.position.x + shoot.targetPoint.x, transform.position.y + shoot.targetPoint.y), shoot.colType));
                }
                shoot.delay = shoot.rate;
            }
        } else if (shoot.delay < 0) {
            if (shoot.aimType == ecs::AimType::AIM_STRAIGHT) {
                    shoot.shots.push_back(shoot.fire(transform.position, shoot.lvl, ::game::Vector2(transform.position.x + shoot.targetPoint.x, transform.position.y + shoot.targetPoint.y), shoot.colType));
            }
            shoot.delay = shoot.rate;
        }
        shoot.delay -= event.dt;
    }
    // for (ecs::Entity &rm : toRm) {
    //     ecs::Coordinator::getInstance().destroyEntity(rm);

    // }
}
