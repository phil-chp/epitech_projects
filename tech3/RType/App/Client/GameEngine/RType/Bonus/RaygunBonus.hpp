/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RaygunBonus
*/

#ifndef RAYGUNBONUS_HPP_
    #define RAYGUNBONUS_HPP_
    #include "GameEngine/IBonus.hpp"
    #include "GameEngine/RType/Shoot/Raygun.hpp"
    #include "GameEngine/RType/Shoot/Projectile.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/GameEntities.hpp"

namespace engine {
    namespace rtype {
        class RaygunBonus : public ::engine::IBonus {
            public:
                RaygunBonus(::game::Vector2 pos = ::game::Vector2(500, 500)) : entLinked(-1)
                {
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
                        {0, {game::Rect(645*0.4, 0*0.4, 185*0.4, 200*0.4)}},
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
                    engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::RaygunBonus>(*this));
                }
                ~RaygunBonus() = default;


                void apply(ecs::Entity entToApply) final {
                    ecs::Bonus &bonus = ecs::Coordinator::getInstance().getComponent<ecs::Bonus>(entToApply);
                    if(bonus.bonus.find(ecs::BonusType::RAYGUN_BONUS) == bonus.bonus.end()) {
                        bonus.bonus[ecs::BonusType::RAYGUN_BONUS] = this->entity;
                        ecs::Shoot &shoot = ecs::Coordinator::getInstance().getComponent<ecs::Shoot>(entToApply);
                        shoot.fire = ::engine::rtype::Raygun::fire;
                        this->entLinked = entToApply;
                    }
                }

                void remove() final {
                    if (entLinked != -1) {
                        ecs::Shoot &shoot = ecs::Coordinator::getInstance().getComponent<ecs::Shoot>(entLinked);
                        shoot.fire = ::engine::rtype::Projectile::fire;

                    }
                    ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(this->entity);
                    alive.dead = true;


                    ecs::Bonus &bonus = ecs::Coordinator::getInstance().getComponent<ecs::Bonus>(entLinked);
                    auto it = bonus.bonus.find(ecs::BonusType::RAYGUN_BONUS);
                    if(it != bonus.bonus.end())
                        bonus.bonus.erase(it);

                }

                ecs::Entity entLinked;
        };
    }
}


#endif
