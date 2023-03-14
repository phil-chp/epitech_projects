/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** AnimationSystem
*/

#ifndef ANIMATIONSYSTEM_HPP_
    #define ANIMATIONSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class AnimationSystem : public ASystem {
        public:
            AnimationSystem() = default;
            ~AnimationSystem() = default;

            void update(float dt) const final;

    };
}

#endif /* !ANIMATIONSYSTEM_HPP_ */
