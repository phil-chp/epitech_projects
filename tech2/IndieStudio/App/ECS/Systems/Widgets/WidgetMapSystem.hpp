/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetSystem
*/

#ifndef WIDGET_MAP_SYSTEM_HPP_
    #define WIDGET_MAP_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"
    #define MAX_MAP 3

namespace ecs {
    class WidgetMapSystem : public ASystem {
        public:
            WidgetMapSystem() {
                this->_mapColors.push_back(rl::RL_PURPLE);
                this->_mapColors.push_back(rl::RL_MAGENTA);
                this->_mapColors.push_back(rl::RL_GREEN);
            }
            ~WidgetMapSystem() = default;
            void update(float dt) const final;

        private:
            void setMapMode(MapWidget &widget) const;
            void selectionMap(MapWidget &widget) const;

            std::vector<rl::Color> _mapColors{};
    };
}

#endif /* !WIDGET_MAP_SYSTEM_HPP_ */
