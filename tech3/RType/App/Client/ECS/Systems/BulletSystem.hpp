/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BulletSystem
*/

#ifndef BULLETSYSTEM_HPP_
#define BULLETSYSTEM_HPP_
    #include "ECS/System.hpp"
    #include "ECS/Component.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/AI.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class BulletSystem : public ASystem {
        public:
            BulletSystem() = default;
            ~BulletSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}

#endif /* !BULLETSYSTEM_HPP_ */
