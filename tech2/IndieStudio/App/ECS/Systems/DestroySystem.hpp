/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** DestroySystem
*/

#ifndef DESTROYSYSTEM_HPP_
#define DESTROYSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {

    class DestroySystem : public ASystem {
        public:
            DestroySystem() = default;
            ~DestroySystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !DESTROYSYSTEM_HPP_ */
