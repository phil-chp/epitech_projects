/*
** EPITECH PROJECT, 2022
** RType
** File description:
** AnimateSystem
*/

#ifndef ANIMATESYSTEM_HPP_
    #define ANIMATESYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Control.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/MoveStat.hpp"
    #include "ECS/Components/SpriteAnimation.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class AnimateSystem : public ASystem {
        public:
            AnimateSystem() = default;
            ~AnimateSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}

#endif /* !ANIMATESYSTEM_HPP_ */
