/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** BoundSystem
*/

#ifndef BOUNDSYSTEM_HPP_
    #define BOUNDSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Bound.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/Transform.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class BoundSystem : public ASystem {
        public:
            BoundSystem() = default;
            ~BoundSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !BOUNDSYSTEM_HPP_ */
