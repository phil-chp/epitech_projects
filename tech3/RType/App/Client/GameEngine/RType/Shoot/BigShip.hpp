/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BigShip
*/

#ifndef BIGSHIP_HPP_
#define BIGSHIP_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/RType/Shoot/BigShipBullet.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/GameEntities.hpp"


namespace engine {
namespace rtype {


class BigShip : public engine::Entity {
    public:



        BigShip(ecs::Entity link, unsigned int playerId = 0, ::game::Vector2 pos = {50, 200}) : engine::Entity(), linkedTo(link)
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Control {
                    .eventID = playerId,
                    .secondary = true
            });
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RigidBody { //Pawn
                    .velocity = {0, 0},
                    .acceleration = {0, 0}
            });
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::MoveStat { // MOVABLE PAWN
                    .maxVelX = 500.0f,
                    .xVel    = 200.0f,
                    .maxVelY = 500.0f,
                    .yVel    = 200.0f,
                    .xAcc    = 75.0f,
                    .yAcc    = 75.0f
            });

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Transform {
                    .position = pos,
                    .rotation = 0.0f,
                    .scale = 1.0f
            });

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Bound {
                    .x = 0,
                    .y = 0,
                    .width = 1920,
                    .height = 1080
            });

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_RTYPE3), false
                }
            );



            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Alive {
                    .hp = 100,
                    .dead = false,
                    .shield = false
                }
            );

            ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 2.5));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 4}, {1, 4}};

            anim.container = {
                {0, {game::Rect(171*2.5, 339*2.5, 32*2.5, 34*2.5),
                    game::Rect(203*2.5, 339*2.5, 32*2.5, 34*2.5), game::Rect(235*2.5, 339*2.5, 32*2.5, 34*2.5), game::Rect(268*2.5, 339*2.5, 32*2.5, 34*2.5)
                }},
                {1, {game::Rect(159*2.5, 407*2.5, 36*2.5, 27*2.5),
                    game::Rect(195*2.5, 407*2.5, 36*2.5, 27*2.5), game::Rect(230*2.5, 407*2.5, 36*2.5, 27*2.5), game::Rect(266*2.5, 407*2.5, 35*2.5, 27*2.5)
                }}
            };
            anim.current = {0, 1};
            anim.delay = 0.2;
            anim.actualDelay = 0.0;
            anim.fix = false;
            anim.toSet = true;
            anim.setTo = {0, 2};
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                anim
            );

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Shoot {
                    .shtType = ::ecs::ShootType::SHT_CONTROL,
                    .amoType = ::ecs::AmmoType::AMO_DEFAULT,
                    .aimType = ::ecs::AimType::AIM_STRAIGHT,
                    .rate = 0.15,
                    .delay = 0,
                    .lvl = 1,
                    .fired = false,
                    .targetPoint = {100, 100},
                    .target = 0,
                    .shots = {},
                    .fire = &engine::rtype::BigShipBullet::fire,
                    .colType = ::ecs::CollisionType::COL_PROJECTILE_ALLY
                }
            );

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Hitbox {
                    .type = ecs::HitBoxType::BOX_SQUARE,
                    .bounds = std::make_shared<engine::Square>(
                        engine::Square(
                            pos,
                            anim.container.at(anim.current.first)[anim.current.second].w * 0.95,
                            anim.container.at(anim.current.first)[anim.current.second].h * 0.95
                    )),
                    .collidesWith = {},
                    .collidedWith = {},
                    .colType = ecs::CollisionType::COL_SHIP_ALLY,
                    .invFrames = 0,
                    .rect = rl::Rectangle(
                        0,
                        0,
                        anim.container.at(anim.current.first)[anim.current.second].w * 0.95,
                        anim.container.at(anim.current.first)[anim.current.second].h * 0.95
            )});
            engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::BigShip>(*this));
        };

        ~BigShip() = default;

        void setPos(::game::Vector2 pos)
        {
            ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(this->entity);
            transform.position = pos;
        }

        ecs::Entity linkedTo;
};
}; // rtype
} // engine


#endif /* !SMALLSHIP_HPP_ */
