/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** TemporarySystem
*/

#ifndef TEMPORARYSYSTEM_HPP_
    #define TEMPORARYSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
    class TemporarySystem : public ASystem {
        public:
            TemporarySystem() = default;
            ~TemporarySystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !TEMPORARYSYSTEM_HPP_ */
