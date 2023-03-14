/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BigShipBonus
*/

#ifndef BIGSHIPBONUS_HPP_
    #define BIGSHIPBONUS_HPP_
    #include "GameEngine/IBonus.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/RType/Shoot/Projectile.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/GameEntities.hpp"
    #include "GameEngine/LinkerEntities.hpp"
    #include "GameEngine/RType/Shoot/BigShip.hpp"

namespace engine {
    namespace rtype {
        class BigShipBonus : public ::engine::IBonus {
            public:
                BigShipBonus(::game::Vector2 pos = ::game::Vector2(500, 500)) : entLinked(-1) {
                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::RigidBody { //Pawn
                            .velocity = {0, 0},
                            .acceleration = {0, 0}
                    });
                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::Alive {
                            .hp = 1,
                            .dead = false,
                            .shield = false
                        }
                    );

                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::Transform { //JSAIS PAS
                            .position = {pos.x, pos.y},
                            .rotation = 0.0f,
                            .scale = 1.0f
                    });

                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::RLDrawable { // GRAPHOBJECT ?
                            SpriteManager::getInstance().getData(SpriteType::SPR_BONUS2), false
                    });
                    ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
                    drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 0.4));

                    ecs::SpriteAnimation anim;
                    anim.max = {{0, 1}};
                    int i = 0;
                    anim.container = {
                        {0, {game::Rect(228*0.4, 0*0.4, 185*0.4, 200*0.4)}},
                    };
                    anim.current = {0, 0};
                    anim.delay = 0.5;
                    anim.actualDelay = 0.5;
                    anim.fix = false;
                    anim.toSet = true;
                    anim.setTo = anim.current;
                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        anim
                    );


                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::Hitbox {
                            .type = ecs::HitBoxType::BOX_SQUARE,
                            .bounds = std::make_shared<engine::Square>(
                                engine::Square(
                                    {0, 0},
                                    anim.container.at(anim.current.first)[anim.current.second].w,
                                    anim.container.at(anim.current.first)[anim.current.second].h
                            )),
                            .collidesWith = {},
                            .collidedWith = {},
                            .colType = ecs::CollisionType::COL_PICKUP,
                            .invFrames = 0,
                            .rect = rl::Rectangle(
                                0,
                                0,
                                anim.container.at(anim.current.first)[anim.current.second].w,
                                anim.container.at(anim.current.first)[anim.current.second].h
                    )});



                    ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::Scroll {
                            .xVel = -30,
                            .yVel = 0,
                            .pause = false
                    });
                    engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::BigShipBonus>(*this));

                }
                ~BigShipBonus() = default;

                void apply(ecs::Entity entToApply) final {
                    ecs::Bonus &bonus = ecs::Coordinator::getInstance().getComponent<ecs::Bonus>(entToApply);
                    if(bonus.bonus.find(ecs::BonusType::BIGSHIP_BONUS) == bonus.bonus.end()) {

                        this->entLinked = entToApply;
                        ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entToApply);
                        ecs::Control &control = ecs::Coordinator::getInstance().getComponent<ecs::Control>(entToApply);
                        engine::rtype::BigShip bigShip(entToApply, control.eventID, ::game::Vector2(transform.position.x + 200, transform.position.y));
                        engine::LinkerEntities::getInstance().addEntity(entToApply, bigShip.entity);
                        this->entityBigShip = bigShip.entity;
                        bonus.bonus[ecs::BonusType::BIGSHIP_BONUS] = this->entityBigShip;
                    }
                }

                void remove() final {
                    // engine::LinkerEntities::getInstance().removeEntity(entityShipManager);
                    ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(this->entity);
                    ecs::Bonus &bonus = ecs::Coordinator::getInstance().getComponent<ecs::Bonus>(entLinked);
                    alive.dead = true;
                    ecs::Alive &aliveOther = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(this->entityBigShip);
                    aliveOther.dead = true;

                    auto it = bonus.bonus.find(ecs::BonusType::BIGSHIP_BONUS);
                    if(it != bonus.bonus.end())
                        bonus.bonus.erase(it);
                }


                ecs::Entity entLinked;
                ecs::Entity entityBigShip;
        };
    }
}


#endif /* !BIGSHIPBONUS_HPP_ */
