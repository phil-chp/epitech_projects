/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/Circle.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/RType/Shoot/Projectile.hpp"
    #include "GameEngine/RType/Shoot/Raygun.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/GameEntities.hpp"


namespace engine {

template <unsigned int N>
class Player : public Entity {
    public:
        Player(bool secondary = false) : engine::Entity()
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Control {
                    .eventID = N,
                    .secondary = secondary
            });
        };
        ~Player() = default;

        static ecs::Entity construct() {
            Player<N> player;
            return (player.entity);
        };
};

namespace rtype {
    const std::vector<::game::Color> playerColor = {
        ::game::Color(7, 203, 242, 0),
        ::game::Color(247, 0, 255, 0),
        ::game::Color(0, 255, 0, 0),
        ::game::Color(255, 0, 0, 0)
    };

template <unsigned int N>
class ShipPlayer : public ::engine::Player<N> {
    public:
        ShipPlayer()  : engine::Player<N>(), playerId(N)
        {

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RigidBody { //Pawn
                    .velocity = {0, 0},
                    .acceleration = {0, 0}
            });

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Transform { //JSAIS PAS
                    .position = {50, N * 200},
                    .rotation = 0.0f,
                    .scale = 1.0f
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
                ecs::Bound {
                    .x = 0,
                    .y = 0,
                    .width = 1920,
                    .height = 1080
            });

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_PLAYER),
                    false,
                    ecs::Entity(-1),
            });
            ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
            // drawable.setSize(game::Vector2(200, 100));
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 4.0));


            ecs::SpriteAnimation anim;
            anim.max = {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}};
            int i = 0;
            int y = 0;
            anim.container = {
                {  i, {game::Rect((y = 0) * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4)}},
                {++i, {game::Rect((y = 0) * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4)}},
                {++i, {game::Rect((y = 0) * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4)}},
                {++i, {game::Rect((y = 0) * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4)}},
                {++i, {game::Rect((y = 0) * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4), game::Rect(++y * 33*4, i * 17*4, 33*4, 17*4)}}
            };
            anim.current = {N, 2};
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
                    .fire = &engine::rtype::Projectile::fire,
                    .colType = ::ecs::CollisionType::COL_PROJECTILE_ALLY
                }
            );

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Hitbox {
                    .type = ecs::HitBoxType::BOX_SQUARE,
                    .bounds = std::make_shared<engine::Square>(
                        engine::Square(
                            {50, N * 200},
                            anim.container.at(anim.current.first)[anim.current.second].w * 0.95,
                            anim.container.at(anim.current.first)[anim.current.second].h * 0.95
                    )),
                    .collidesWith = {},
                    .collidedWith = {},
                    .colType = ecs::CollisionType::COL_PLAYER,
                    .invFrames = 0,
                    .rect = rl::Rectangle(
                        0,
                        0,
                        anim.container.at(anim.current.first)[anim.current.second].w * 0.95,
                        anim.container.at(anim.current.first)[anim.current.second].h * 0.95
            )});

            engine::rtype::Propulsion propulsor(this->entity, playerColor[N]);

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
                ecs::Bonus {
                    .hasBonus = true,
                    .bonus = {}
                }
            );
            engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::ShipPlayer<N>>(*this));
        }

        ~ShipPlayer() {};

        static ecs::Entity construct() {
            ShipPlayer<N> player;
            return (player.entity);
        }

        // ecs::Entity shaderLinked;
        unsigned int playerId;


};

template <unsigned int N>
class AttachShip : public ::engine::Player<N> {
    public:
        AttachShip();
        ~AttachShip();
};
}; // namespace rtype
} // namespace engine

#endif /* !PLAYER_HPP_ */
