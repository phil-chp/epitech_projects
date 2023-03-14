/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** CyborgBobEnemy
*/

#ifndef CYBORGBOBENEMY_HPP_
    #define CYBORGBOBENEMY_HPP_

    #include "GameEngine/Entity.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/RType/Shoot/Projectile.hpp"
    #include "GameEngine/RType/Shoot/RaygunEnemy.hpp"

    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/RType/Particles/Destruction.hpp"
    #include "GameEngine/RType/AI/AI.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/RType/Enemy/Enemy.hpp"


namespace engine {
namespace rtype {
    class CyborgBobEnemy : public engine::rtype::Enemy {
        public:
            CyborgBobEnemy()
                : engine::rtype::Enemy() {
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RigidBody { //Pawn
                        .velocity = {0, 0},
                        .acceleration = {0, 0}
                });

                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Transform { //JSAIS PAS
                        .position = {1400, 100},
                        .rotation = 0.0f,
                        .scale = 1.0f
                });


                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RLDrawable { // GRAPHOBJECT ?
                        SpriteManager::getInstance().getData(SpriteType::SPR_CYBORG_BOB),
                        false
                });
                ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
                drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 2.0));

                ecs::SpriteAnimation anim;
                anim.max = {{0, 2}};
                anim.container = {
                    {0, {game::Rect(34*2, 33*2, 34*2, 34*2), game::Rect(67*2, 33*2, 34*2, 34*2)}}
                };
                anim.current = {0, 0};
                anim.delay = 0.2;
                anim.actualDelay = 0.2;
                anim.fix = false;
                anim.toSet = true;
                anim.setTo = anim.current;
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    anim
                );

                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Shoot {
                        .shtType = ::ecs::ShootType::SHT_AUTO,
                        .amoType = ::ecs::AmmoType::AMO_DEFAULT,
                        .aimType = ::ecs::AimType::AIM_STRAIGHT,
                        .rate = 0.9,
                        .delay = 0.9,
                        .lvl = 1,
                        .fired = false,
                        .targetPoint = {100, 0},
                        .target = 0,
                        .shots = {},
                        .fire = &engine::rtype::RaygunEnemy::fire,
                        .colType = ::ecs::CollisionType::COL_PROJECTILE_ENEMY
                    }
                );


                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Hitbox {
                        .type = ecs::HitBoxType::BOX_SQUARE,
                        .bounds = std::make_shared<engine::Square>(
                            engine::Square(
                                {0, 0},
                                anim.container.at(anim.current.first)[anim.current.second].w * 0.90,
                                anim.container.at(anim.current.first)[anim.current.second].h * 0.90
                        )),
                        .collidesWith = {},
                        .colType = ecs::CollisionType::COL_ENEMY,
                        .invFrames = 0,
                        .rect = rl::Rectangle(
                            0,
                            0,
                            anim.container.at(anim.current.first)[anim.current.second].w * 0.90,
                            anim.container.at(anim.current.first)[anim.current.second].h * 0.90
                )});
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Alive {
                        .hp = 100,
                        .dead = false,
                        .shield = false
                    }
                );


                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Scroll {
                        .xVel = -30,
                        .yVel = 0,
                        .pause = false
                });
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::AI {
                        .move  = {ecs::AIMoveType::AIMOV_STRAIGHT, {-50, 0}, 0, {0, 0}, false, &engine::rtype::AI::move},
                        .shoot = {ecs::AimType::AIM_STRAIGHT, 0, {-50, 0}, false},
                        .lifeTime = 0
                });
            };
            ~CyborgBobEnemy() = default;

            static ecs::Entity construct() {
                CyborgBobEnemy enemy;
                return (enemy.entity);
            }

            // engine::rtype::Destruction destroy;

    };
} //engine
} //rtype
#endif
