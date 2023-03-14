/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ShootSystem
*/

#ifndef SHOOT_SYSTEM_HPP_
    #define SHOOT_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Shoot.hpp"
    #include "ECS/Components/Transform.hpp"


namespace ecs {

    class ShootSystem : public ASystem {
        public:
            ShootSystem() = default;
            ~ShootSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !SHOOT_SYSTEM_HPP_ */
