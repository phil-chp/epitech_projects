/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Square
*/

#ifndef SQUARE_HPP_
    #define SQUARE_HPP_

    #include "GameEngine/Shape.hpp"


namespace engine {
    class Square : public AShape {
        public:
            Square(game::Vector2 pos = {0, 0}, unsigned int a = 0, unsigned int b = 0)
                : AShape(SHP_SQUARE, pos, a, b) {};
            ~Square() = default;


            bool collidesSquare(std::shared_ptr<AShape> othr) const {
                if (this->pos.x + this->val.a >= othr->pos.x && \
                    this->pos.x <= othr->pos.x + othr->val.a && \
                    this->pos.y + this->val.b >= othr->pos.y && \
                    this->pos.y <= othr->pos.y + othr->val.b) {
                        return true;
                }
                return false;
            };
            bool collidesSquare(const AShape &othr) const {
                if (this->pos.x + this->val.a >= othr.pos.x && \
                    this->pos.x <= othr.pos.x + othr.val.a && \
                    this->pos.y + this->val.b >= othr.pos.y && \
                    this->pos.y <= othr.pos.y + othr.val.b) {
                        return true;
                }
                return false;
            };
            bool collidesCircle(std::shared_ptr<AShape> othr) const {
                std::cout << "collide Square->Circle" << std::endl;
                return false;
            };
            bool collidesCircle(const AShape &othr) const {
                std::cout << "collide Square->Circle" << std::endl;
                return false;
            };

            virtual bool collides(std::shared_ptr<AShape> othr) const override  {
                if (othr->type == SHP_SQUARE) {
                    return this->collidesSquare(othr);
                } else if (othr->type == SHP_RING) {
                    return this->collidesCircle(othr);
                }
                return false;
            }

            virtual bool collides(const AShape &othr) const override  {
                if (othr.type == SHP_SQUARE) {
                    return this->collidesSquare(othr);
                } else if (othr.type == SHP_RING) {
                    return this->collidesCircle(othr);
                }
                return false;
            }

            AShape getCollisionRect(std::shared_ptr<AShape> otr) const final {

                AShape rec;

                if (otr->type != engine::ShapeType::SHP_SQUARE) {
                    return rec;
                }
                rec.type = engine::ShapeType::SHP_SQUARE;

                float dxx = fabsf(this->pos.x - otr->pos.x);
                float dyy = fabsf(this->pos.y - otr->pos.y);

                if (this->pos.x <= otr->pos.x) {
                    if (this->pos.y <= otr->pos.y) {
                        rec.pos.x = otr->pos.x;
                        rec.pos.y = otr->pos.y;
                        rec.val.a = this->val.a - dxx;
                        rec.val.b = this->val.b - dyy;
                    } else {
                        rec.pos.x = otr->pos.x;
                        rec.pos.y = this->pos.y;
                        rec.val.a = this->val.a - dxx;
                        rec.val.b = otr->val.b - dyy;
                    }
                } else {
                    if (this->pos.y <= otr->pos.y) {
                        rec.pos.x = this->pos.x;
                        rec.pos.y = otr->pos.y;
                        rec.val.a = otr->val.a - dxx;
                        rec.val.b = this->val.b - dyy;
                    } else {
                        rec.pos.x = this->pos.x;
                        rec.pos.y = this->pos.y;
                        rec.val.a = otr->val.a - dxx;
                        rec.val.b = otr->val.b - dyy;
                    }
                }

                if (this->val.a > otr->val.a) {
                    if (rec.val.a >= otr->val.a) rec.val.a = otr->val.a;
                } else {
                    if (rec.val.a >= this->val.a) rec.val.a = this->val.a;
                }

                if (this->val.b > otr->val.b) {
                    if (rec.val.b >= otr->val.b) rec.val.b = otr->val.b;
                } else {
                    if (rec.val.b >= this->val.b) rec.val.b = this->val.b;
                }
                return rec;

            }
    };
} //engine
#endif
