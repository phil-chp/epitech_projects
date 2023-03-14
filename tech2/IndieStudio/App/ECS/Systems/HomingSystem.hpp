/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** HomingSystem
*/

#ifndef HOMINGSYSTEM_HPP_
    #define HOMINGSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
    class HomingSystem : public ASystem {
        public:
            HomingSystem() = default;
            ~HomingSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !HomingSYSTEM_HPP_ */
