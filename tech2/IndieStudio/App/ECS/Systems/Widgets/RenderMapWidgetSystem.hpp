/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderWidgetSystem
*/

#ifndef RENDER_MAP_WIDGET_SYSTEM_HPP_
    #define RENDER_MAP_WIDGET_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class RenderMapWidgetSystem : public ASystem {
        public:
            RenderMapWidgetSystem() = default;
            ~RenderMapWidgetSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !RENDER_MAP_WIDGET_SYSTEM_HPP_ */
