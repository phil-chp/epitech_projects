/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
    #define CIRCLE_HPP_

    #include "GameEngine/Shape.hpp"


namespace engine {
    class Circle : public AShape {
        public:
            Circle(game::Vector2 center = {0, 0}, unsigned int a = 0, unsigned int b = 0)
                : AShape(SHP_RING, pos, a, b) {};
            ~Circle() = default;

            virtual bool collides(std::shared_ptr<AShape> othr) const override {

                if (othr->type == SHP_SQUARE) {
                    return this->collidesSquare(othr);
                } else if (othr->type == SHP_RING) {
                    return this->collidesCircle(othr);
                }
                return false;
            }

            bool collidesSquare(std::shared_ptr<AShape> othr) const {
                return false;
            };
            bool collidesCircle(std::shared_ptr<AShape> othr) const {
                return false;
            };
    };
} //engine
#endif
