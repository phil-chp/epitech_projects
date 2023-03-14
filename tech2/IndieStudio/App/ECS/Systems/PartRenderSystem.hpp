
/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** PartRenderSystem
*/

#ifndef PARTRENDERSYSTEM_HPP_
    #define PARTRENDERSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class PartRenderSystem : public ASystem {
        public:
            PartRenderSystem() = default;
            ~PartRenderSystem() = default;

            void update(float dt) const final;

    };
}


#endif /* !PARTRENDERSYSTEM_HPP_ */