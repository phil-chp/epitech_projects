/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ParticulesSystem
*/

#ifndef PARALLAXSYSTEM_HPP
    #define PARALLAXSYSTEM_HPP

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Parallax.hpp"

namespace ecs {

    class ParallaxSystem : public ASystem {
        public:
            ParallaxSystem() = default;
            ~ParallaxSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !PARALLAXSYSTEM_HPP */
