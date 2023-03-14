/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** BombSystem
*/

#define _USE_MATH_DEFINES

#include "BombSystem.hpp"


void ecs::BombSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Bomb &bomb = ecs::Coordinator::getInstance().getComponent<Bomb>(entity);
        Transform3D &trans = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);
        Temporary &temp = ecs::Coordinator::getInstance().getComponent<Temporary>(entity);
        Alive &alive = ecs::Coordinator::getInstance().getComponent<Alive>(entity);
        if (!temp.done && !alive.dead) {
            continue;
        }
        rl::SoundManager::getInstance().getData(rl::SOUND_BOMB_EXPLODE).play();


        try {
            PlayerStat &stats = ecs::Coordinator::getInstance().getComponent<PlayerStat>(bomb.entity);
            --stats.bombOut;
        } catch (ECSError &e) {}

        Entity spread = ecs::Coordinator::getInstance().createEntity();

        ecs::Coordinator::getInstance().addComponent(
            spread,
            ecs::DrawableModel {
                .model = rl::Model(rl::MODEL_BOMB),
                .factor = 1.0f,
                .type = rl::MODEL_BOMB
        });
        ecs::Coordinator::getInstance().addComponent(
            spread,
            ecs::Damage {
                .damage = 5
        });
        ecs::Coordinator::getInstance().addComponent(
            spread,
            ecs::Transform3D {
                .position = rl::Vector3(trans.position.x, trans.position.y, trans.position.z),
                .rotation = rl::Vector3(0, 0, 0),
                .scale = rl::Vector3(1.0f)
            }
        );
        ecs::Coordinator::getInstance().addComponent(
            spread,
            ecs::Temporary {
                .delay = 0.85,
                .done = false
        });
        ecs::Coordinator::getInstance().addComponent(
            spread,
            ecs::RigidBody{
                .velocity = rl::Vector3(0.0f, 0.0f, 0.0f),
                .acceleration = rl::Vector3(0, 0, 0),
                .type = ecs::CollisionType::SPREAD,
                .grounded = true,
                .movable = true,
                .mass = 10
        });
        ecs::Coordinator::getInstance().addComponent(
            spread,
            ecs::Spread{
                .fire = bomb.size,
                .posX = trans.position,
                .posZ = trans.position,
                .sizeXPos = 0,
                .sizeZPos = 0,
                .sizeXNeg = 0,
                .sizeZNeg = 0
        });
    }
}
