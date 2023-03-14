/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** ParticulesSystem
*/

#ifndef PARTICLESSYSTEM_HPP_
    #define PARTICLESSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {

    class ParticlesSystem : public ASystem {
        public:
            ParticlesSystem() = default;
            ~ParticlesSystem() = default;

            void update(float dt) const final;

    };
}

#endif /* !PARTICLESSYSTEM_HPP_ */