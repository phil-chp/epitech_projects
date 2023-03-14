/*
** EPITECH PROJECT, 2022
** B-CPP-775-NCE-5-1-rtype-philippe.cheype [WSL : Ubuntu]
** File description:
** Shield
*/

#ifndef SHIELD_HPP_
#define SHIELD_HPP_
    #include "GameEngine/Entity.hpp"
    #include "ECS/Components/Particles.hpp"
    #include "ECS/Components/RLParticles.hpp"


    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Particles/Particles.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Random.hpp"
    #include <bits/stdc++.h>
    #include <math.h>

    #define MAX_PARTICLES 100


namespace engine {
namespace rtype {

    const std::vector<::game::Color> shieldColor = {
        ::game::Color(210, 0, 255, 255),
        ::game::Color(255, 0, 210, 255),
        ::game::Color(104, 11, 122, 255)
    };
class Shield {
    public:
        Shield(ecs::Entity ent, ::game::Color color = ::game::Color(255, 0, 210, 255))
        {
            ::game::Vector2 pos = ::ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(ent).position;
            pos.x += 20;
            pos.y += 40;

            float alpha = ::game::Random::getRandomValue(0, 2 * M_PI);
            float cosA = cos(alpha);
            float sinA = sin(alpha);
            pos.y += cosA * 75;
            pos.x += sinA * 75;

            std::vector<rl::Particle> particles;
            particles.reserve(MAX_PARTICLES);
            for (int i = 0; i < 40; i++) {
                int rand = ::game::Random::getRandomIntValue(0, 2);
                ::game::Vector2 velocity = ::game::Vector2( cosA * -20, sinA * -20 );
                particles.emplace_back(velocity, pos, shieldColor[rand]);
            }
            ::ecs::Coordinator::getInstance().addComponent(
                ent,
                ecs::RLParticles (
                    particles,
                    ecs::ParticlesType::SHIELD,
                    &engine::rtype::Shield::update,
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
            if (particles.size() < 100) {
                for (int i = 0; i < 3; ++i) {
                    float alpha = ::game::Random::getRandomValue(0, 2 * M_PI);
                    float cosA = cos(alpha);
                    float sinA = sin(alpha);
                    int rand = ::game::Random::getRandomIntValue(0, 2);
                    ::game::Color color(particles[0].color.r, particles[0].color.g, particles[0].color.b, 255);
                    ::game::Vector2 velocity = ::game::Vector2(  cosA * -20, sinA * -20  );
                    ::game::Vector2 pos = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(ent).position;
                    pos.x += 20;
                    pos.y += 40;
                    ::game::Vector2 modif = ::game::Vector2( (float)cos(alpha), (float)sin(alpha));
                    // modif.normalize();
                    modif.x *= 75;
                    modif.y *= 75;
                    pos += modif;
                    particles.emplace_back(velocity, pos, shieldColor[rand]);
                }
            }

        }

        // Shield(::game::Vector2& pos) noexcept {
		// 	  system.reserve(MAX_PARTICLES);

        //     for (int i = 0; i < MAX_PARTICLES; i++) {
        //         system.emplace_back(pos);
        //     }

        // }
        // ~Shield() = default;

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
