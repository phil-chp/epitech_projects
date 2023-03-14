/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetSystem
*/

#ifndef WIDGET_BUTTON_SYSTEM_HPP_
    #define WIDGET_BUTTON_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class WidgetButtonSystem : public ASystem {
        public:
            WidgetButtonSystem() = default;
            ~WidgetButtonSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !WIDGET_BUTTON_SYSTEM_HPP_ */
