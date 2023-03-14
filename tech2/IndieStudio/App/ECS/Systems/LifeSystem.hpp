/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** LifeSystem
*/

#ifndef LIFESYSTEM_HPP_
    #define LIFESYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class LifeSystem : public ASystem {
        public:
            LifeSystem() = default;
            ~LifeSystem() = default;

            void update(float dt) const final;

    };
}

#endif /* !LIFESYSTEM_HPP_ */
