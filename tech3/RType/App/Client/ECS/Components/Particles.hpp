/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Particles
*/

#ifndef PARTICLES_HPP_
#define PARTICLES_HPP_

    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include "ECS/Entity.hpp"

namespace ecs {
    enum ParticlesType {
        NONE = -1,
        PROPULSION,
        DESTRUCTION,
        SHIELD
    };

    template <typename T, typename K>
    class Particles {

        public:

            Particles() = default;
            Particles(T particles, ParticlesType type, void (*func)(ecs::Entity, T &, float), ::game::Vector2 offset) : _particles(particles), _type(type), upd(func), _offset(offset) {};
            ~Particles() = default;

            void update(ecs::Entity ent, float dt);
            void draw();

            T _particles;
            ParticlesType _type;
            ::game::Vector2 _offset;
            void (*upd) (ecs::Entity, T&, float);
    };
};

#endif /* !PARTICLES_HPP_ */
