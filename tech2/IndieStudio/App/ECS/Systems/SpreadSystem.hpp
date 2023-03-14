/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** SpreadSystem
*/


#ifndef SPREADSYSTEM_HPP_
    #define SPREADSYSTEM_HPP_


    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
    class SpreadSystem : public ASystem {
        public:
            SpreadSystem() = default;
            ~SpreadSystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !SPREADSYSTEM_HPP_ */