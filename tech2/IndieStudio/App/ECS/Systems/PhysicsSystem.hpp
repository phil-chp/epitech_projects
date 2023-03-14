/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** PhysicsSystem
*/

#ifndef PHYSICSSYSTEM_HPP_
    #define PHYSICSSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class PhysicsSystem : public ASystem {
        public:
            PhysicsSystem() = default;
            ~PhysicsSystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !PHYSICSSYSTEM_HPP_ */
