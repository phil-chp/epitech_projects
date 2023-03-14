/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ScrollSystem
*/

#ifndef SCROLLSYSTEM_HPP_
    #define SCROLLSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class ScrollSystem : public ASystem {
        public:
            ScrollSystem() = default;
            ~ScrollSystem() = default;

            void update(::engine::PollEvent &event) const final;

    };
}
#endif /* !SCROLLSYSTEM_HPP_ */
