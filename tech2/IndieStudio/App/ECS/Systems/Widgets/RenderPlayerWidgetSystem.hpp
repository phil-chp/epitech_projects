/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderWidgetSystem
*/

#ifndef RENDER_PLAYER_WIDGET_SYSTEM_HPP_
    #define RENDER_PLAYER_WIDGET_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class RenderPlayerWidgetSystem : public ASystem {
        public:
            RenderPlayerWidgetSystem() = default;
            ~RenderPlayerWidgetSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !RENDER_PLAYER_WIDGET_SYSTEM_HPP_ */
