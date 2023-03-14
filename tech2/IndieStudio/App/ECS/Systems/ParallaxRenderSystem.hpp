/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ParticulesSystem
*/

#ifndef PARALLAXRENDERSYSTEM_HPP
    #define PARALLAXRENDERSYSTEM_HPP

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Parallax.hpp"

namespace ecs {

    class ParallaxRenderSystem : public ASystem {
        public:
            ParallaxRenderSystem() = default;
            ~ParallaxRenderSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !PARALLAXRENDERSYSTEM_HPP */
