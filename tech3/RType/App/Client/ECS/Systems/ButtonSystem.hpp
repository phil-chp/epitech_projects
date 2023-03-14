/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ButtonSystem
*/

#ifndef BUTTONSYSTEM_HPP_
    #define BUTTONSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Button.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/Transform.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class ButtonSystem : public ASystem {
        public:
            ButtonSystem() = default;
            ~ButtonSystem() = default;

            void update(::engine::PollEvent &event) const final;
    };
}
#endif /* !BUTTONSYSTEM_HPP_ */
