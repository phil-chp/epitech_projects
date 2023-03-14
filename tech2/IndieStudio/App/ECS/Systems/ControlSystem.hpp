/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ControlSystem
*/

#ifndef CONTROLSYSTEM_HPP_
    #define CONTROLSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"
    #include <cmath>

namespace ecs {

    class ControlSystem : public ASystem {
        public:
            ControlSystem() = default;
            ~ControlSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !CONTROLSYSTEM_HPP_ */
