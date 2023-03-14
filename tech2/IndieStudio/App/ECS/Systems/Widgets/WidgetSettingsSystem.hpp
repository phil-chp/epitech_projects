/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetSystem
*/

#ifndef WIDGET_SETTINGS_HPP_
    #define WIDGET_SETTINGS_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class WidgetSettingsSystem : public ASystem {
        public:
            WidgetSettingsSystem() = default;
            ~WidgetSettingsSystem() = default;
            void update(float dt) const final;

        private:
            void setNewKey(ControlWidget &widget, rl::KeyboardKeys const &newKey) const;
            void setWidgetKey(ControlWidget &widget, uint8_t index) const;
    };
}

#endif /* !WIDGET_SETTINGS_HPP_ */
