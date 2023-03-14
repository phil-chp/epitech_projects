/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Vector4
*/

#ifndef VECTOR4_HPP_
    #define VECTOR4_HPP_

    #include "Raylib-cpp.hpp"
    #include <iostream>
    #include <cmath>

namespace rl {
    struct Vector4 : public ::Vector4 {
        Vector4() : ::Vector4{0, 0, 0, 0} {};
        explicit Vector4(::Vector4 const &vect) : ::Vector4{vect} {};
        Vector4(float x, float y, float z, float w) : ::Vector4{x, y, z, w} {};
        explicit Vector4(float n) : ::Vector4{n, n, n, n} {};
        ~Vector4() = default;

        void operator=(::Vector4 const &vect) {
            this->x = vect.x;
            this->y = vect.y;
            this->z = vect.z;
            this->w = vect.w;
        }

        //* Custom ---------------------------------------------------------- //

        Vector4 distance(Vector4 const &end) const {
            return Vector4(end.x - this->x, end.y - this->y, end.z - this->z, end.w - this->w);
        }
        Vector4 round() const {
            return Vector4(std::round(this->x), std::round(this->y), std::round(this->z), std::round(this->w));
        };

        //* Built-in -------------------------------------------------------- //

        //* Operators ------------------------------------------------------- //

        Vector4 operator*(Vector4 const &vec) {
            return { this->x * vec.x, this->y * vec.y, this->z * vec.z, this->w * vec.w };
        }
        Vector4 operator+(Vector4 const &vec) {
            return { this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w };
        }
        Vector4 operator-(Vector4 const &vec) {
            return { this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w };
        }

        Vector4 operator/(Vector4 const &vec) {
            if (vec.x == 0 || vec.y == 0 || vec.z == 0 || vec.w == 0)
                return { 0, 0, 0, 0 };
            return { this->x / vec.x, this->y / vec.y, this->z / vec.z, this->w / vec.w };
        }

        Vector4 operator*(float val) {
            return { this->x * val, this->y * val, this->z * val, this->w * val };
        }

        Vector4 operator/(float val) {
            if (val == 0)
                return { 0, 0, 0, 0 };
            return { this->x / val, this->y / val, this->z / val, this->w / val };
        }

        void operator*=(Vector4 const &vec) {
            *this = *this * vec;
        }
        // void operator+=(Vector4 const &vec) {
        //     *this = *this + vec;
        // }
        // void operator-=(Vector4 const &vec) {
        //     *this = *this - vec;
        // }
        // void operator/=(Vector4 const &vec) {
        //     *this = *this / vec;
        // }

        void debug() {
            std::cout << "Vector4: " << this->x << " " << this->y << " " << this->z << " " << this->w << std::endl;
        }
    };
}
#endif /* !VECTOR4_HPP_ */
