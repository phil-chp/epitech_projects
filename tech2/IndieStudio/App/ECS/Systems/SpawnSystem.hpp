/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** SpawnSystem
*/

#ifndef SPAWNSYSTEM_HPP_
    #define SPAWNSYSTEM_HPP_


    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
    class SpawnSystem : public ASystem {
        public:
            SpawnSystem() = default;
            ~SpawnSystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !SPAWNSYSTEM_HPP_ */
