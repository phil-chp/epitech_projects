/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Shape
*/

#ifndef SHAPE_HPP_
    #define SHAPE_HPP_

    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include <memory>


namespace engine {
    enum ShapeType {
        SHP_SHAPE   =-1,
        SHP_SQUARE  = 0,
        SHP_RING    = 1
    };
    class AShape {
        public:
            AShape(ShapeType type = SHP_SHAPE, game::Vector2 pos = {0, 0}, unsigned int a = 0, unsigned int b = 0)
                : type(type), pos(pos), val({a, b}) {};
            ~AShape() = default;
            virtual bool collides(std::shared_ptr<AShape> othr) const {
                return false;
            };
            virtual bool collides(const AShape &othr) const {
                return false;
            };
            virtual void moveTo(game::Vector2 pos) {
                this->pos = pos;
            };

            virtual AShape getCollisionRect(std::shared_ptr<AShape> otr) const {
                return AShape();
            }

            ShapeType type;
            game::Vector2 pos;
            struct {
                unsigned int a;
                unsigned int b;
            } val;
    };
} //engine
#endif
