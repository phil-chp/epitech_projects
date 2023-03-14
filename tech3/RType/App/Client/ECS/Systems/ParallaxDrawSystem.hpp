/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ParallaxSystem
*/

#ifndef PARALLAXDRAWSYSTEM_HPP_
    #define PARALLAXDRAWSYSTEM_HPP_

    #include "ECS/Components/RLBackground.hpp"
    #include "ECS/Components/Transform.hpp"
    #include "ECS/Components/Parallax.hpp"
    #include "ECS/System.hpp"
    #include "GameEngine/PollEvent.hpp"

namespace ecs {

    class ParallaxDrawSystem : public ASystem {
        public:
            ParallaxDrawSystem() = default;
            ~ParallaxDrawSystem() = default;

            void update(::engine::PollEvent &) const final;

    };
}

#endif /* !PARALLAXDRAWSYSTEM_HPP_ */
