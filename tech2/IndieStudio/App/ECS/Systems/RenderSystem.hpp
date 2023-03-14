/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#ifndef RENDERSYSTEM_HPP_
    #define RENDERSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class RenderSystem : public ASystem {
        public:
            RenderSystem() = default;
            ~RenderSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !RENDERSYSTEM_HPP_ */
