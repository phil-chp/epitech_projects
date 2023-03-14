 /*
** EPITECH PROJECT, 2022
** RType
** File description:
** SmallShip
*/

#ifndef SMALLSHIP_HPP_
#define SMALLSHIP_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/RType/Shoot/SmallShipBullet.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {


class SmallShip : public engine::Entity {
    public:



        SmallShip(unsigned int playerId = 0, ::game::Vector2 pos = {50, 200}, int ship = 0) : engine::Entity()
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Control {
                    .eventID = playerId,
                    .secondary = false
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
            anim.max = {{0, 6}};

            anim.container = {
                {0, {game::Rect(157*2.5, 32*2.5, 25*2.5, 23*2.5),
                    game::Rect(181*2.5, 32*2.5, 25*2.5, 23*2.5), game::Rect(205*2.5, 32*2.5, 25*2.5, 23*2.5), game::Rect(229*2.5, 32*2.5, 25*2.5, 23*2.5),
                    game::Rect(252*2.5, 32*2.5, 25*2.5, 23*2.5), game::Rect(277*2.5, 32*2.5, 25*2.5, 23*2.5)
                }}
            };
            anim.current = {0, 1};
            anim.delay = 0.3;
            anim.actualDelay = 0.0;
            anim.fix = false;
            anim.toSet = true;
            anim.setTo = {0, 2};
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                anim
            );

            if (ship == 0) {

                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Shoot {
                        .shtType = ::ecs::ShootType::SHT_CONTROL,
                        .amoType = ::ecs::AmmoType::AMO_DEFAULT,
                        .aimType = ::ecs::AimType::AIM_STRAIGHT,
                        .rate = 0.5,
                        .delay = 0,
                        .lvl = 1,
                        .fired = false,
                        .targetPoint = {100, 0},
                        .target = 0,
                        .shots = {},
                        .fire = &engine::rtype::SmallShipBullet::fireShipUp,
                        .colType = ::ecs::CollisionType::COL_PROJECTILE_ALLY
                    }
                );
            } else {
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Shoot {
                        .shtType = ::ecs::ShootType::SHT_CONTROL,
                        .amoType = ::ecs::AmmoType::AMO_DEFAULT,
                        .aimType = ::ecs::AimType::AIM_STRAIGHT,
                        .rate = 0.5,
                        .delay = 0,
                        .lvl = 1,
                        .fired = false,
                        .targetPoint = {100, 0},
                        .target = 0,
                        .shots = {},
                        .fire = &engine::rtype::SmallShipBullet::fireShipDown,
                        .colType = ::ecs::CollisionType::COL_PROJECTILE_ALLY
                    }
                );
            }
        };

        ~SmallShip() = default;

        void setPos(::game::Vector2 pos)
        {
            ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(this->entity);
            transform.position = pos;
        }
};
}; // rtype
} // engine


#endif /* !SMALLSHIP_HPP_ */
