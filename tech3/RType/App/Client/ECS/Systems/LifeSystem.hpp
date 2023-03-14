/*
** EPITECH PROJECT, 2022
** RType
** File description:
** LifeSystem
*/

#ifndef LIFESYSTEM_HPP_
#define LIFESYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Control.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/MoveStat.hpp"
    #include "ECS/Components/SpriteAnimation.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class LifeSystem : public ASystem {
        public:
            LifeSystem() = default;
            ~LifeSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}

#endif /* !LIFESYSTEM_HPP_ */
