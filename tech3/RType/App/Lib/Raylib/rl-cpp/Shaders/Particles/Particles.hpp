/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Particles
*/


#ifndef RLPARTICLES_HPP_
    #define RLPARTICLES_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib.hpp"
    #include "Lib/Raylib/rl-cpp/Shapes/Shapes.hpp"
    #include "Utils/Random.hpp"
    #include <exception>
    #include <string>

namespace rl {

        class Particle final{
        public:
            Vector2 acc;
            Vector2 position;
            Vector2 velocity;
            float size;
            float lifeTime;
            float lifeExpectency;
            Color color;

            Particle(Vector2 velocity = rl::Vector2((float)::game::Random::getRandomValue(-100, -50), (float)::game::Random::getRandomValue(-15, 15)), Vector2 pos = rl::Vector2(0.0, 0.0),  ::game::Color col = ::game::Color(0, 255, 0, 255), float lifeExpectency = 0.75f)
                :position(pos)  , lifeExpectency(lifeExpectency), lifeTime(0.0f)
            {
                this->acc = rl::Vector2{-1.0f, 0.0f};
                // this->velocity = rl::Vector2{ (float)::game::Random::getRandomValue(-100, -50), (float)::game::Random::getRandomValue(-15, 15) };
                this->velocity = velocity;
                this->size = 5.0f;

                this->color = col;
            }

            void draw() const {
                        // DrawCircle(position.x, position.y, size, RED);
                        // rl::Circle3 c = rl::Circle(position.x, position.y, size);
                        // c.draw(RED);
                        rl::Rectangle rec = rl::Rectangle(position.x, position.y, size, size, this->color);
                        rec.draw();
                        // DrawRectangle(position.x, position.y, size, size, ORANGE);
                // DrawCircleLines(position.x, position.y, size, RAYWHITE);
            }

            bool isDead() const {
                return lifeTime > lifeExpectency;
            }
    };
}

#endif /* !PARTICLES_HPP_ */
