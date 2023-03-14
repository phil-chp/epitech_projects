/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ControlSystem
*/

#include "ControlSystem.hpp"


void ecs::ControlSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Controlled &control = ecs::Coordinator::getInstance().getComponent<Controlled>(entity);
        RigidBody &body     = ecs::Coordinator::getInstance().getComponent<RigidBody>(entity);
        Transform3D &trans  = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);
        PlayerStat &stat  = ecs::Coordinator::getInstance().getComponent<PlayerStat>(entity);

        // if (rl::Keyboard::isKeyDown(control.up) && body.velocity.y <= 0) {
        //         body.velocity.y = 8;
        //         body.acceleration.y = 5;
        //         body.grounded = false;
        // }
            // body.acceleration.y += 0.5;
        // if (rl::Keyboard::isKeyDown(control.bomb)) {
        //     body.acceleration.y -= 0.3;
        // }
        if (rl::Keyboard::isKeyPressed(control.place) && stat.bombOut < stat.bombMax) {
            rl::SoundManager::getInstance().getData(rl::SOUND_BOMB_PLACE).play();
            ++stat.bombOut;
            Entity bomb = ecs::Coordinator::getInstance().createEntity();
            ecs::Coordinator::getInstance().addComponent(
                bomb,
                ecs::Bomb {
                    .size = stat.fire,
                    .entity = entity
            });
            ecs::Coordinator::getInstance().addComponent(
                bomb,
                ecs::Temporary {
                    .delay = 2,
                    .done = false
            });
            ecs::Coordinator::getInstance().addComponent(
                bomb,
                ecs::DrawableModel {
                   .model = rl::Model(rl::MODEL_BOMB),
                   .factor = 1.5f,
                .type = rl::MODEL_BOMB
            });
            ecs::Coordinator::getInstance().addComponent(
                bomb,
                ecs::Alive {
                    .dead = false,
                    .health = 1,
                    .armor = 0
            });
            ecs::Coordinator::getInstance().addComponent(
                bomb,
                ecs::Transform3D {
                    .position = {
                        std::round(trans.position.x),
                        trans.position.y,
                        std::round(trans.position.z)
                    },
                    .rotation = trans.rotation,
                    .scale = trans.scale * 0.90
            });
            ecs::Coordinator::getInstance().addComponent(
                bomb,
                ecs::RigidBody {
                    .velocity = rl::Vector3(0.0f, 0.0f, 0.0f),
                    .acceleration = rl::Vector3(0, 0, 0),
                    .type = ecs::CollisionType::BOMB,
                    .grounded = false,
                    .movable = true,
                    .mass = 3
            });
            // ecs::Coordinator::getInstance().addComponent(
            //     bomb,
            //     ecs::Gravity{rl::Vector3(0, -9.807, 0)
            // });
        }
        if (rl::Keyboard::isKeyPressed(control.front) || rl::Keyboard::isKeyPressed(control.back) || rl::Keyboard::isKeyPressed(control.left) || rl::Keyboard::isKeyPressed(control.right)) {
            rl::SoundManager::getInstance().getData(rl::SOUND_PLAYER_STEP).play();
        }

        if (rl::Keyboard::isKeyDown(control.right)) {
            trans.rotation.y = -90.0f;
            if (body.velocity.x < 0) {
                body.velocity.x = 0.5;
            }
            if (body.velocity.x < stat.speedMax) {
                body.velocity.x += 0.5;
            }
        }
        if (rl::Keyboard::isKeyDown(control.left)) {
            trans.rotation.y = 90.0f;
            if (body.velocity.x > 0) {
                body.velocity.x = -0.5;
            }
            if (body.velocity.x > -stat.speedMax) {
                body.velocity.x -= 0.5;
        }}
        if (rl::Keyboard::isKeyDown(control.front)) {
            trans.rotation.y = 180.0f;
            if (body.velocity.z > 0) {
                body.velocity.z = -0.5;
            }
            if (body.velocity.z > -stat.speedMax) {
                body.velocity.z -= 0.5;
        }}
        if (rl::Keyboard::isKeyDown(control.back)) {
            trans.rotation.y = 0.0f;
            if (body.velocity.z < 0) {
                body.velocity.z = 0.5;
            }
            if (body.velocity.z < stat.speedMax) {
                body.velocity.z += 0.5;
        }}
    }
}
// void ecs::ControlSystem::update(float dt) const {
//     // TODO: unused parameter ?
//     (void)dt;
//     for (ecs::Entity const &entity : this->entities) {
//         Controlled &control = ecs::Coordinator::getInstance().getComponent<Controlled>(entity);
//         RigidBody &body = ecs::Coordinator::getInstance().getComponent<RigidBody>(entity);
//         Transform3D &trans = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);

//         if (IsKeyPressed(control.go) && ((trans.position.x > 0) != (body.acceleration.x > 0))) {
//             body.acceleration *= -1;
//             control.coming = false;
//         }
//         if (IsKeyPressed(control.come) && ((trans.position.x > 0) == (body.acceleration.x > 0))) {
//             body.acceleration *= -1;
//             control.coming = true;
//         }
//     }
// }
