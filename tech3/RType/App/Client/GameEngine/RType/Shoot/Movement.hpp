/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Movement
*/

#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_


    #include "GameEngine/Projectile.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {
class Movement {
    public:
        Movement();
        ~Movement();
    /// TODO: faut mettre un lifetime dans le projectile et lenvoyer en arg
        static void updateSin(ecs::Entity entity, ::engine::PollEvent &event) {
            ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
            ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
            // int x = body.velocity.x - event.dt;
            int y  = sin(trans.position.x / 100) *300;
            body.velocity.y = y;
        }

        static void updateNegSin(ecs::Entity entity, ::engine::PollEvent &event) {
            ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
            ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
            // int x = body.velocity.x - event.dt;
            int y  = sin(trans.position.x / 100) *300 * -1;
            body.velocity.y = y;
            body.velocity.x *= -1;
        }

        static void updateCos(ecs::Entity entity, ::engine::PollEvent &event) {
            ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
            ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
            // int x = body.velocity.x - event.dt;
            int y  = -sin(trans.position.x / 100) *300;
            body.velocity.y = y;

        }
        static void updateStraight(ecs::Entity entity, ::engine::PollEvent &event) {
            // body.velocity.y +=
        }
};
}
}

#endif /* !MOVEMENT_HPP_ */
