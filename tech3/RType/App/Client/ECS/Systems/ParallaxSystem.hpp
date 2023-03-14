/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ParallaxSystem
*/

#ifndef PARALLAXSYSTEM_HPP_
    #define PARALLAXSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class ParallaxSystem : public ASystem {
        public:
            ParallaxSystem() = default;
            ~ParallaxSystem() = default;

            void update(::engine::PollEvent &) const final;

    };
}

#endif /* !PARALLAXSYSTEM_HPP_ */
