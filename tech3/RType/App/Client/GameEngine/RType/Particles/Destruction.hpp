/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Destruction
*/

#ifndef DESTRUCTION_HPP_
#define DESTRUCTION_HPP_
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
    const std::vector<::game::Color> explosionColor = {
        ::game::Color(30, 30, 30, 255),
        ::game::Color(144, 72, 52, 255),
        ::game::Color(250, 43, 8, 255),
        ::game::Color(228, 148, 23, 255),
        ::game::Color(241, 53, 12, 255)
    };
    const std::vector<::game::Vector2> explosionVelocity = {
        ::game::Vector2(-70.0, 70.0),
        ::game::Vector2(-50.0, 50.0),
        ::game::Vector2(-30.0, 30.0),
        ::game::Vector2(-20.0, 20.0),
        ::game::Vector2(-10.0, 10.0)
    };

class Destruction : public Entity {
    public:
        Destruction(::game::Vector2 pos) : engine::Entity()
        {
            ::game::Vector2 pos1 = ::game::Vector2(pos.x + 50, pos.y + 50);
            std::vector<rl::Particle> particles;
            particles.reserve(MAX_PARTICLES);
            for (int i = 0; i < 100; i++) {
                int rand = ::game::Random::getRandomIntValue(0, 4);
                ::game::Vector2 velocity = ::game::Vector2( (float)::game::Random::getRandomValue(explosionVelocity[rand].x, explosionVelocity[rand].y), (float)::game::Random::getRandomValue(explosionVelocity[rand].x, explosionVelocity[rand].y) );
                velocity.normalize();
                velocity.x *= ::game::Random::getRandomValue(0, explosionVelocity[rand].y);
                velocity.y *= ::game::Random::getRandomValue(0, explosionVelocity[rand].y);
                particles.emplace_back(velocity, pos1, explosionColor[rand]);
            }

            ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Transform { //JSAIS PAS
                        .position = {pos1.x , pos1.y},
                        .rotation = 0.0f,
                        .scale = 1.0f
            });
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLParticles (
                    particles,
                    ecs::ParticlesType::DESTRUCTION,
                    &engine::rtype::Destruction::update,
                    ::game::Vector2(0, 0)
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

        }

        // Destruction(::game::Vector2& pos) noexcept {
		// 	  system.reserve(MAX_PARTICLES);

        //     for (int i = 0; i < MAX_PARTICLES; i++) {
        //         system.emplace_back(pos);
        //     }

        // }
        // ~Destruction() = default;

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
