/*
** EPITECH PROJECT, 2022
** RType
** File description:
** AISystem
*/

#ifndef AISYSTEM_HPP_
    #define AISYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Component.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/AI.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class AISystem : public ASystem {
        public:
            AISystem() = default;
            ~AISystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}

#endif /* !AISYSTEM_HPP_ */
