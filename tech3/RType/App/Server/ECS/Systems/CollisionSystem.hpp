/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Collision
*/

#ifndef COLLISIONSYSTEM_HPP_
    #define COLLISIONSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Hitbox.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/Transform.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class CollisionSystem : public ASystem {
        public:
            CollisionSystem() = default;
            ~CollisionSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !COLLISIONSYSTEM_HPP_ */
