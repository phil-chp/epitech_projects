/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Beric
*/

#ifndef BERIC_HPP_
    #define BERIC_HPP_

    #include "GameEngine/Entity.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/RType/Shoot/Projectile.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/RType/Particles/Destruction.hpp"
    #include "GameEngine/RType/AI/AI.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/RType/Shoot/TripleBullet.hpp"

    #include "GameEngine/Boss.hpp"


namespace engine {
namespace rtype {



    class Beric : public engine::Boss {
        public:
            enum BericActionType {
                NONE = -1,
                ENTRANCE,
                MULTISHOOT1,
                MULTISHOOT2,
                REPLACE,
                MOVE,
                SHIELD
            };
            Beric()
                : engine::Boss() {
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RigidBody { //Pawn
                        .velocity = {0, 0},
                        .acceleration = {0, 0}
                });

                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Transform { //JSAIS PAS
                        .position = {2200, 400},
                        .rotation = 0.0f,
                        .scale = 1.0f
                });


                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RLDrawable { // GRAPHOBJECT ?
                        SpriteManager::getInstance().getData(SpriteType::SPR_BERIC),
                        false
                });
                ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
                drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 4.0));

                ecs::SpriteAnimation anim;
                anim.max = {{0, 1}};
                int i = 0;
                anim.container = {
                    {0, {game::Rect(0*4, 0*4, 130*4, 50*4)}}
                };
                anim.current = {0, 0};
                anim.delay = 0.2;
                anim.actualDelay = 0.2;
                anim.fix = true;
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
                        .rate = 2,
                        .delay = 2,
                        .lvl = 1,
                        .fired = false,
                        .targetPoint = {100, 0},
                        .target = 0,
                        .shots = {},
                        .fire = &engine::rtype::TripleBullet::fire,
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
                        .shoot = {},
                        .lifeTime = 0
                });

                this->bericAction = {
                    {BericActionType::ENTRANCE, &engine::rtype::Beric::entrance},
                    {BericActionType::MULTISHOOT1, &engine::rtype::Beric::MultiSoot1},
                    {BericActionType::MULTISHOOT2, &engine::rtype::Beric::MultiShoot2},
                    {BericActionType::MOVE, &engine::rtype::Beric::MoveCircle},
                    {BericActionType::SHIELD, &engine::rtype::Beric::Shield},
                    {BericActionType::REPLACE, &engine::rtype::Beric::replace}
                };

                this->action = bericAction.at(BericActionType::ENTRANCE);
                this->nbReps = 60;
            };
            ~Beric() = default;

            static void entrance(engine::Boss* beric) {
                engine::rtype::Beric *bericPtr = static_cast<engine::rtype::Beric *>(beric);
                ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(bericPtr->entity);

                if (trans.position.x <= 1600) {
                    beric->action = bericPtr->bericAction.at(BericActionType::MOVE);
                    beric->nbReps = 1;
                }

            }

            static void replace(engine::Boss* beric) {
                engine::rtype::Beric *bericPtr = static_cast<engine::rtype::Beric *>(beric);
                ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(bericPtr->entity);
                ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(beric->entity);
                ai.move  = {ecs::AIMoveType::AIMOV_STRAIGHT, {0, 0}, 0, {1600, 400}, false, &engine::rtype::AI::moveTo};

                if (beric->nbReps == 0) {
                    // beric->action = beric->bericAction.at(BericActionType::MULTISHOOT2);
                    beric->nbReps = 1;
                    beric->action = bericPtr->bericAction.at(BericActionType::SHIELD);
                }
                beric->nbReps--;
            }

            static void MultiSoot1(engine::Boss* beric) {
                // std::cout << "MultiSoot1" << std::endl;
                engine::rtype::Beric *bericPtr = static_cast<engine::rtype::Beric *>(beric);
                ecs::Shoot &shoot = ecs::Coordinator::getInstance().getComponent<ecs::Shoot>(bericPtr->entity);
                ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(bericPtr->entity);
                ai.shoot = {ecs::AimType::AIM_STRAIGHT, 0, {-100, 0}, false};
                // std::cout << "Frame: " <<  beric->nbReps << std::endl;



                if (beric->nbReps == 0) {
                    // beric->action = beric->bericAction.at(BericActionType::MULTISHOOT2);
                    beric->nbReps = 500;
                    beric->action = bericPtr->bericAction.at(BericActionType::REPLACE);
                }
                beric->nbReps--;
            }

            static void MultiShoot2(engine::Boss* beric) {
                // std::cout << "MultiSoot2" << std::endl;

                engine::rtype::Beric *bericPtr = static_cast<engine::rtype::Beric *>(beric);
                beric->action = bericPtr->bericAction.at(BericActionType::SHIELD);
            }

            static void MoveCircle(engine::Boss* beric) {
                engine::rtype::Beric *bericPtr = static_cast<engine::rtype::Beric *>(beric);
                ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(beric->entity);

                ai.move = {ecs::AIMoveType::AIMOV_STRAIGHT, {0.0, 0.0}, 0, {1000.0, 400.0}, false, &engine::rtype::AI::moveCircleV2};
                beric->nbReps = 1000;
                beric->action = bericPtr->bericAction.at(BericActionType::MULTISHOOT1);
            }

            static void Shield(engine::Boss* beric) {
                // std::cout << "MultiSoot4" << std::endl;
                engine::rtype::Beric *bericPtr = static_cast<engine::rtype::Beric *>(beric);
                ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(beric->entity);
                ai.move  = {ecs::AIMoveType::AIMOV_STRAIGHT, {0, 0}, 0, {0, 0}, false, &engine::rtype::AI::move};
                // beric->action = bericPtr->bericAction.at(BericActionType::MULTISHOOT1);
            }

            std::map<BericActionType, void (*)(engine::Boss*)> bericAction;

            // engine::rtype::Destruction destroy;

    };
} //engine
} //rtype
#endif
