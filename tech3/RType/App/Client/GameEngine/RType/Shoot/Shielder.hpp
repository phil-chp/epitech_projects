/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Shielder
*/

#ifndef SHIELDSHIP_HPP_
#define SHIELDSHIP_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/RType/Particles/Shield.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {


class Shielder : public engine::Entity {
    public:

        Shielder(unsigned int playerId = 0, ::game::Vector2 pos = {50, 200}) : engine::Entity()
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
                ecs::Alive {
                    .hp = 100,
                    .dead = false,
                    .shield = false
                }
            );


            engine::rtype::Shield shield(this->entity);
        };

        ~Shielder() = default;

        void setPos(::game::Vector2 pos)
        {
            ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(this->entity);
            transform.position = pos;
        }


};
}; // rtype
} // engine


#endif /* !SMALLSHIP_HPP_ */
