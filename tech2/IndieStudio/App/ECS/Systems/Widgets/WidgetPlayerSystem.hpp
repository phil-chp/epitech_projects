/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetSystem
*/

#ifndef WIDGET_PLAYER_SYSTEM_HPP_
    #define WIDGET_PLAYER_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class WidgetPlayerSystem : public ASystem {
        public:
            WidgetPlayerSystem() {
                this->_playerColors.push_back(rl::RL_WHITE);
                this->_playerColors.push_back(rl::RL_BLACK);
                this->_playerColors.push_back(rl::RL_RED);
                this->_playerColors.push_back(rl::RL_GREEN);
                this->_playerColors.push_back(rl::RL_BLUE);
                this->_playerColors.push_back(rl::RL_YELLOW);
            }
            ~WidgetPlayerSystem() = default;
            void update(float dt) const final;

        private:
            void setPlayerMode(PlayerWidget &widget) const;
            void selectionPlayer(PlayerWidget &widget) const;

            std::vector<rl::Color> _playerColors{};
    };
}

#endif /* !WIDGET_PLAYER_SYSTEM_HPP_ */
