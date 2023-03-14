/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderModelSystem
*/

#ifndef RENDERMODELSYSTEM_HPP_
    #define RENDERMODELSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class RenderModelSystem : public ASystem {
        public:
            RenderModelSystem() = default;
            ~RenderModelSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !RENDERMODELSYSTEM_HPP_ */
