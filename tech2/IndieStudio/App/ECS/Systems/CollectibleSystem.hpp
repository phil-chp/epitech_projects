/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** CollectibleSystem
*/

#ifndef COLLECTIBLESYSTEM_HPP_
    #define COLLECTIBLESYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Item.hpp"


namespace ecs {
    class CollectibleSystem : public ASystem {
        public:
            CollectibleSystem()  = default;
            ~CollectibleSystem() = default;

            void update(float dt) const final;
    };
}
#endif /* !COLLECTIBLESYSTEM_HPP_ */
