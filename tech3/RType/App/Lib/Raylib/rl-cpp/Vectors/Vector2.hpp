/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Vector2
*/

#ifndef RLVECTOR2_HPP_
    #define RLVECTOR2_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Utils/Vector2.hpp"
    #include <iostream>
    #include <cmath>

namespace rl {
    struct Vector2 : public ::Vector2 {
        Vector2() : ::Vector2{0, 0} {};
        explicit Vector2(::Vector2 const &vect) : ::Vector2{vect} {};
        Vector2(float x, float y) : ::Vector2{x, y} {};
        explicit Vector2(float n) : ::Vector2{n, n} {};
        Vector2(game::Vector2 const &vect) : ::Vector2{vect.x, vect.y} {};
        ~Vector2() = default;

        //* Custom ---------------------------------------------------------- //

        void operator=(game::Vector2 const &vect)
        {
            this->x = vect.x;
            this->y = vect.y;
        }

        Vector2 distance(Vector2 const &end) const {
            return Vector2(end.x - this->x, end.y - this->y);
        }

        Vector2 round() const {
            return Vector2(std::round(this->x), std::round(this->y));
        }

        Vector2 direction() const {
            return (Vector2(this->x / fabs(this->x), this->y / fabs(this->y)));
        }

        //* Operators ------------------------------------------------------- //
        Vector2 operator*(Vector2 const &vec) {
            return rl::Vector2(std::move(::Vector2Multiply(*this, vec))); }
        Vector2 operator+(Vector2 const &vec) {
            return rl::Vector2(std::move(::Vector2Add(*this, vec))); }
        Vector2 operator-(Vector2 const &vec) {
            return rl::Vector2(std::move(::Vector2Subtract(*this, vec))); }
        Vector2 operator/(Vector2 const &vec) {
            if (vec.x == 0 || vec.y == 0) return Vector2(0, 0);
            return { this->x / vec.x, this->y / vec.y };
            }
        void operator=(::Vector2 const &vect) {
            this->x = vect.x;
            this->y = vect.y;
        }
        Vector2 operator/(float n) {
            if (n == 0) return Vector2(0, 0);
            return { this->x / n, this->y / n };
        }
        Vector2 operator*(float n) {
            return { this->x * n, this->y * n };
        }

        void operator*=(Vector2 const &vec) { *this = std::move(*this * vec); }
        void operator+=(Vector2 const &vec) { *this = std::move(*this + vec); }
        void operator-=(Vector2 const &vec) { *this = std::move(*this - vec); }
        void operator/=(Vector2 const &vec) { *this = std::move(*this / vec); }
        bool operator==(Vector2 const &vec) { return (this->x == vec.x && this->y == vec.y); }

        //* Built-in -------------------------------------------------------- //
        // Vector with components value 0.0f
        void zero() { *this = ::Vector2Zero(); }

        // Vector with components value 1.0f
        void one() { *this = ::Vector2One(); }

        // Add two vectors
        void add(Vector2 const &vect) { *this = ::Vector2Add(*this, vect); }

        // Add vector and float value
        void addValue(float value) { *this = ::Vector2AddValue(*this, value); }

        // Subtract two vectors
        void subtract(Vector2 const &vect) { *this = ::Vector2Subtract(*this, vect); }

        // Subtract vector by float value
        void subtractValue(float value) { *this = ::Vector2SubtractValue(*this, value); }

        // Scale vector (multiply by value)
        void scale(float scale) { *this = ::Vector2Scale(*this, scale); }

        // Multiply vector by vector
        void multiply(Vector2 const &vect) { *this = ::Vector2Multiply(*this, vect); }

        // Negate provided vector (invert direction)
        void negate() { *this = ::Vector2Negate(*this); }

        // Calculate vector length
        float length() { return ::Vector2Length(*this); }

        // Calculate vector square length
        float lengthSqr() { return ::Vector2LengthSqr(*this); }

        // Calculate distance between two vectors
        float distance(Vector2 const &end) { return ::Vector2Distance(*this, end); }

        // Calculate angle from two vectors
        float angle(Vector2 const &end) { return ::Vector2Angle(*this, end); }

        // Divide vector by vector
        void divide(Vector2 const &vect) { *this = ::Vector2Divide(*this, vect); }

        // Rotate vector by angle
        void rotate(float angle) { *this = ::Vector2Rotate(*this, angle); }

        // Calculate linear interpolation between two vectors
        void lerp(Vector2 const &vect, float amount) { *this = ::Vector2Lerp(*this, vect, amount); }

        // Calculate reflected vector to normal
        void reflect(Vector2 const &normal) { *this = ::Vector2Reflect(*this, normal); }

        // Move Vector towards target
        void moveTowards(Vector2 const &target, float maxDistanceDelta) {
            *this = ::Vector2MoveTowards(*this, target, maxDistanceDelta);
        }

        void debug() {
            std::cout << "Vector2: " << this->x << " " << this->y << std::endl;
        }
    };
}
#endif /* !RLVECTOR2_HPP_ */
