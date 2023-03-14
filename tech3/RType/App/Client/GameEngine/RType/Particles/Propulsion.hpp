/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Propulsion
*/

#ifndef PROPULSION_HPP_
#define PROPULSION_HPP_
    #include "GameEngine/Entity.hpp"
    #include "ECS/Components/Particles.hpp"
    #include "ECS/Components/RLParticles.hpp"


    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Particles/Particles.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Random.hpp"
    #include <bits/stdc++.h>

    #define MAX_PARTICLES 100


namespace engine {
namespace rtype {
class Propulsion {
    public:
        Propulsion(ecs::Entity ent, ::game::Color color = ::game::Color(255, 0, 0, 255))
        {
            ::game::Vector2 pos = ::ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(ent).position;

            std::vector<rl::Particle> particles;
            particles.reserve(MAX_PARTICLES);
            for (int i = 0; i < 40; i++) {
                ::game::Vector2 velocity = ::game::Vector2( (float)::game::Random::getRandomValue(-100, -50), (float)::game::Random::getRandomValue(-15, 15) );
                particles.emplace_back(velocity, pos, color);
            }
            ::ecs::Coordinator::getInstance().addComponent(
                ent,
                ecs::RLParticles (
                    particles,
                    ecs::ParticlesType::PROPULSION,
                    &engine::rtype::Propulsion::update,
                    ::game::Vector2(0, 5)
                )
            );
        };


        static void update(ecs::Entity ent, std::vector<rl::Particle> &particles, float dt) {

            particles.erase(
                std::remove_if(particles.begin(), particles.end(), [dt]( auto& p ){
                    // this->upd(dt, p); return p.isDead();
                    p.velocity += p.acc * dt;
                    p.position += p.velocity * dt;
                    if (::game::Random::getRandomValue(0, 100) < 60)
                        p.lifeTime += dt;
                    return p.isDead();
                } ),
                particles.end()
            );
            ::game::Color color(particles[0].color.r, particles[0].color.g, particles[0].color.b, 255);
            ::game::Vector2 velocity = ::game::Vector2( (float)::game::Random::getRandomValue(-100, -50), (float)::game::Random::getRandomValue(-15, 15) );
            if (particles.size() < 100) {
                for (int i = 0; i < 3; ++i) {
                    ::game::Vector2 pos = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(ent).position;
                    pos.y += ::game::Random::getRandomValue(15, 45);
                    pos.x += ::game::Random::getRandomValue(-20, 5);
                    particles.emplace_back(velocity, pos, color);
                }
            }

        }

        // Propulsion(::game::Vector2& pos) noexcept {
		// 	  system.reserve(MAX_PARTICLES);

        //     for (int i = 0; i < MAX_PARTICLES; i++) {
        //         system.emplace_back(pos);
        //     }

        // }
        // ~Propulsion() = default;

        // void draw(){
        //     for (std::vector<rl::Particle>::iterator obj = system.begin(); obj < system.end(); obj++) {
        //         (*obj).draw();
        //     }

        // }

        // void update(){
        //     system.erase(
        //         std::remove_if( system.begin(), system.end(), []( auto& p ){
        //            p.update(); return p.size <= 0;
        //         } ),
        //         system.end()
        //     );

        // }

        // std::vector<rl::Particle> system;
};
}
}
#endif /* !PROPULSION_HPP_ */
