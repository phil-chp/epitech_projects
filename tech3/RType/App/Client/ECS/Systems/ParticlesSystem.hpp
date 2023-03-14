/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ParticlesSystem
*/

#ifndef PARTICLESSYSTEM_HPP_
#define PARTICLESSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/RLParticles.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class ParticlesSystem : public ASystem {
    public:
        ParticlesSystem() = default;
        ~ParticlesSystem() = default;

        void update(::engine::PollEvent &event) const final;
};
}
#endif /* !PARTICLESSYSTEM_HPP_ */
