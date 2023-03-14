/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ControlMoveSystem
*/

#ifndef CONTROLMOVESYSTEM_HPP_
    #define CONTROLMOVESYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Control.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/MoveStat.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class ControlMoveSystem : public ASystem {
        public:
            ControlMoveSystem() = default;
            ~ControlMoveSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !CONTROLMOVESYSTEM_HPP_ */
