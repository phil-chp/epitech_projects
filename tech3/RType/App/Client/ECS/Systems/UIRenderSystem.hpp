/*
** EPITECH PROJECT, 2022
** RType
** File description:
** UIRenderSystem
*/

#ifndef UI_SYSTEM_HPP_
    #define UI_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "ECS/Components/UI.hpp"
    #include "ECS/Components/Transform.hpp"

namespace ecs {
    class UIRenderSystem : public ASystem {
        public:
            UIRenderSystem() = default;
            ~UIRenderSystem() = default;

            void update(::engine::PollEvent &event) const final;
    };
}// ecs
#endif
