/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** SpreadSystem
*/

#include "SpreadSystem.hpp"

void ecs::SpreadSystem::update(float dt) const {
    (void)dt;
    std::vector<Entity> toRemove;
    for (ecs::Entity const &entity : this->entities) {
        // std::cout << "SPREAD SYSTEM applied to entity : " << entity << std::endl;
        Spread &spr = ecs::Coordinator::getInstance().getComponent<Spread>(entity);

        Entity particles = ecs::Coordinator::getInstance().createEntity();
        ecs::Coordinator::getInstance().addComponent(
            particles,
            ecs::Particles(spr.posX, rl::Vector4(spr.sizeXPos, spr.sizeZPos, spr.sizeXNeg, spr.sizeZNeg))
        );
        spr.posX.x += (float)(spr.sizeXPos - spr.sizeXNeg) / 2;
        spr.posZ.z += (float)(spr.sizeZPos - spr.sizeZNeg) / 2;

        Entity explosionX = ecs::Coordinator::getInstance().createEntity();
        // ecs::Coordinator::getInstance().addComponent(
        //     explosionX,
        //     ecs::Drawable {
        //         .drawable = rl::Cube(rl::Vector3(0), rl::Vector3(0), rl::Color(200, 0, 0, 150)),
        //         .shadow = true
        // });
        ecs::Coordinator::getInstance().addComponent(
            explosionX,
            ecs::Damage {
                .damage = 5
        });
        ecs::Coordinator::getInstance().addComponent(
            explosionX,
            ecs::Transform3D {
                .position = spr.posX,
                .rotation = rl::Vector3(0, 0, 0),
                .scale = rl::Vector3(spr.sizeXPos + spr.sizeXNeg + 1, 1, 0.95)
            }
        );
        ecs::Coordinator::getInstance().addComponent(
            explosionX,
            ecs::Temporary {
                .delay = 0.85,
                .done = false
        });
        ecs::Coordinator::getInstance().addComponent(
            explosionX,
            ecs::RigidBody{
                .velocity = rl::Vector3(0.0f, 0.0f, 0.0f),
                .acceleration = rl::Vector3(0, 0, 0),
                .type = ecs::CollisionType::HIT,
                .grounded = true,
                .movable = true,
                .mass = 10
        });
        ecs::Coordinator::getInstance().addComponent(
            explosionX,
            ecs::Drawable{
                .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f), rl::Color(252, 65, 3, 25)),
                .texture =  rl::Texture(rl::TEXTURE_MISSING),
                .shadow = false
        });
        Entity explosionZ = ecs::Coordinator::getInstance().createEntity();
        // ecs::Coordinator::getInstance().addComponent(
        //     explosionZ,
        //     ecs::Drawable {
        //         .drawable = rl::Cube(rl::Vector3(0), rl::Vector3(0), rl::Color(200, 0, 0, 150)),
        //         .shadow = true
        //     }
        // );
        ecs::Coordinator::getInstance().addComponent(
            explosionZ,
            ecs::Transform3D {
                .position = spr.posZ,
                .rotation = rl::Vector3(0, 0, 0),
                .scale = rl::Vector3(0.95, 1, spr.sizeZPos + spr.sizeZNeg + 1)
            }
        );
        ecs::Coordinator::getInstance().addComponent(
            explosionZ,
            ecs::Temporary {
                .delay = 0.85,
                .done = false
        });
        ecs::Coordinator::getInstance().addComponent(
            explosionZ,
            ecs::Damage {
                .damage = 5
        });
        ecs::Coordinator::getInstance().addComponent(
            explosionZ,
            ecs::RigidBody{
                .velocity = rl::Vector3(0.0f, 0.0f, 0.0f),
                .acceleration = rl::Vector3(0, 0, 0),
                .type = ecs::CollisionType::HIT,
                .grounded = true,
                .movable = true,
                .mass = 10
        });
        ecs::Coordinator::getInstance().addComponent(
            explosionZ,
            ecs::Drawable{
                .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f), rl::Color(255, 0, 0, 25)),
                .texture =  rl::Texture(rl::TEXTURE_MISSING),
                .shadow = false
        });

        toRemove.push_back(entity);
    }

    for (ecs::Entity entity : toRemove) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}
