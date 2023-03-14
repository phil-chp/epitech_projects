/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Wall
*/

#ifndef WALL_HPP_
    #define WALL_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/Circle.hpp"
    #include "GameEngine/Entity.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include "ECS/Coordinator.hpp"


namespace engine {

    #define WALLXSIZE 100
    #define WALLYSIZE 100

    class Wall : public Entity {
        public:
            Wall(::game::Vector2 pos = {0, 0}, int size = 0) : Entity() {
                ecs::Coordinator &coord = ecs::Coordinator::getInstance();
                coord.addComponent(
                    this->entity,
                    ::ecs::Transform{
                        .position = pos,
                        .rotation = 0,
                        .scale = 1.0

                    }
                );
                coord.addComponent(
                    this->entity,
                    ::ecs::Hitbox{
                        .type = ecs::HitBoxType::BOX_SQUARE,
                        .bounds = std::make_shared<engine::Square>(
                            engine::Square(
                                {0, 0},
                                100,
                                100 * size
                        )),
                        .collidesWith = {},
                        .collidedWith = {},
                        .colType = ::ecs::CollisionType::COL_WALL,
                        .invFrames = 0,
                        .rect = ::rl::Rectangle(
                            0,
                            0,
                            100,
                            100 * size)
                    }
                );
                coord.addComponent(
                    this->entity,
                    ::ecs::Scroll{
                        .xVel = -100,
                        .yVel = 0,
                        .pause = false
                    }
                );
                // coord.addComponent(
                //     this->entity,
                //     ::ecs::RigidBody {
                //         .velocity = {0, 0},
                //         .acceleration = {0, 0}
                //     }
                // );
                ::rl::Texture texture = SpriteManager::getInstance().getData(SpriteType::SPR_WALL);
                // texture.setSize(::rl::Vector2(100, 100 * size));
                texture.setScale(::rl::Vector2(1, size));
                // texture.drawRec(0, 0, 100, 100 * size);
                // coord.addComponent(
                //     this->entity,
                //     ::ecs::RLDrawable {
                //         texture,
                //         false
                //     }
                // );
            }
            ~Wall() = default;

        // private:

    };
}

#endif
