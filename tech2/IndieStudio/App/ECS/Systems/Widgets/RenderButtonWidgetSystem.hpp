/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderWidgetSystem
*/

#ifndef RENDER_BUTTON_WIDGET_SYSTEM_HPP_
    #define RENDER_BUTTON_WIDGET_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class RenderButtonWidgetSystem : public ASystem {
        public:
            RenderButtonWidgetSystem() = default;
            ~RenderButtonWidgetSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !RENDER_BUTTON_WIDGET_SYSTEM_HPP_ */
