/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** BombSystem
*/

#ifndef BOMBSYSTEM_HPP_
    #define BOMBSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"
    #include <cmath>
    #include <future>

namespace ecs {

    class BombSystem : public ASystem {
        public:
            BombSystem() = default;
            ~BombSystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !BOMBSYSTEM_HPP_ */
