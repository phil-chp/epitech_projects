/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
    #define VECTOR2_HPP_
    #include <iostream>
    #include <cmath>
    #define _USE_MATH_DEFINES

namespace game {

    class Vector2 {
        public:
            Vector2() : x(0), y(0) {};
            Vector2(float x, float y) : x(x), y(y) {};
            ~Vector2() = default;

            float x;
            float y;

            // Operators Vector2 ~ Vector2
            Vector2 operator+(const Vector2 &other) const {
                return Vector2(x + other.x, y + other.y);
            }

            Vector2 operator-(const Vector2 &other) const {
                return Vector2(x - other.x, y - other.y);
            }

            Vector2 operator*(const Vector2 &other) const {
                return Vector2(x * other.x, y * other.y);
            }

            Vector2 operator/(const Vector2 &other) const {
                return Vector2(x / other.x, y / other.y);
            }

            // Operators Vector2 ~= Vector2
            Vector2 &operator+=(const Vector2 &other) {
                x += other.x;
                y += other.y;
                return *this;
            }

            Vector2 &operator-=(const Vector2 &other) {
                x -= other.x;
                y -= other.y;
                return *this;
            }

            Vector2 &operator*=(const Vector2 &other) {
                x *= other.x;
                y *= other.y;
                return *this;
            }

            Vector2 &operator/=(const Vector2 &other) {
                x /= other.x;
                y /= other.y;
                return *this;
            }

            // Operators Vector2 ~ Float
            Vector2 operator+(float other) const {
                return Vector2(x + other, y + other);
            }

            Vector2 operator-(float other) const {
                return Vector2(x - other, y - other);
            }

            Vector2 operator*(float other) const {
                return Vector2(x * other, y * other);
            }

            Vector2 operator/(float other) const {
                return Vector2(x / other, y / other);
            }

            // Operators Vector2 ~= Float

            Vector2 &operator+=(float other) {
                x += other;
                y += other;
                return *this;
            }

            Vector2 &operator-=(float other) {
                x -= other;
                y -= other;
                return *this;
            }

            Vector2 &operator*=(float other) {
                x *= other;
                y *= other;
                return *this;
            }

            Vector2 &operator/=(float other) {
                x /= other;
                y /= other;
                return *this;
            }

            // Other operators
            void dump()
            {
                std::cout << "Vector: " << this->x << " x, " << this->y << " y" << std::endl;
            }

            Vector2 &normalize() {
                float length = sqrt(x * x + y * y);
                if (length != 0) {
                    x /= length;
                    y /= length;
                }
                return *this;
            }

    };
};

#endif /* !VECTOR2_HPP_ */
