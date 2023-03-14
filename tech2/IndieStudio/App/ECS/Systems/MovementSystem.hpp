/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** MovementSystem
*/

#ifndef MOVEMENTSYSTEM_HPP_
    #define MOVEMENTSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class MovementSystem : public ASystem {
        public:
            MovementSystem() = default;
            ~MovementSystem() = default;

            void update(float dt) const final;

    };
}

#endif /* !MOVEMENTSYSTEM_HPP_ */
