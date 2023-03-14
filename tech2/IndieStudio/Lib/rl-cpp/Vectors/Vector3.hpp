/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Vector3
*/

#ifndef VECTOR3_HPP_
    #define VECTOR3_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include <iostream>
    #include <string>
    #include <cmath>

namespace rl {
    struct Vector3 : public ::Vector3 {
        Vector3(float n = 0.0f) : ::Vector3{n, n, n} {};
        explicit Vector3(::Vector3 const &vect) : ::Vector3{vect} {};
        Vector3(float x, float y, float z) : ::Vector3{x, y, z} {};
        Vector3(float x, float y, float z, std::string Normalize) : ::Vector3{::Vector3Normalize(::Vector3{x, y, z})}
        {
            Normalize = "Normalize";
        };

        ~Vector3() = default;

        //* Custom ---------------------------------------------------------- //
        Vector3 distance(Vector3 const &end) const {
            return Vector3(end.x - this->x, end.y - this->y, end.z - this->z);
        }

        Vector3 round() const {
            return Vector3(std::round(this->x), std::round(this->y), std::round(this->z));
        };

        Vector3 direction() const {
            return (Vector3(this->x / fabs(this->x), this->y / fabs(this->y), this->z / fabs(this->z)));
        }

        //* Built-in -------------------------------------------------------- //
        // Vector with components value 0.0f
        void zero() { *this = ::Vector3Zero(); }

        // Vector with components value 1.0f
        void one() { *this = ::Vector3One(); }

        // Add two vectors
        void add(Vector3 const &vect) { *this = ::Vector3Add(*this, vect); }

        // Add vector and float value
        void addValue(float value) { *this = ::Vector3AddValue(*this, value); }

        // Subtract two vectors
        void subtract(Vector3 const &vect) { *this = ::Vector3Subtract(*this, vect); }

        // Subtract vector by float value
        void subtractValue(float value) { *this = ::Vector3SubtractValue(*this, value); }

        // Multiply vector by scalar
        void scale(float value) { *this = ::Vector3Scale(*this, value); }

        // Multiply vector by vector
        void multiply(Vector3 const &vect) { *this = ::Vector3Multiply(*this, vect); }

        // Calculate two vectors cross product
        void cross(Vector3 const &vect) { *this = ::Vector3CrossProduct(*this, vect); }

        // Calculate one vector perpendicular vector
        void perpendicular() { *this = ::Vector3Perpendicular(*this); }

        // Calculate vector length
        float length() const { return ::Vector3Length(*this); }

        // Calculate vector square length
        float lengthSqr() const { return ::Vector3LengthSqr(*this); }

        // Calculate distance between two vectors
        float distanceVect(Vector3 const &vect) const { return ::Vector3Distance(*this, vect); }

        // TODO: copy/paste from raymath.h, it's broken somehow
        // Calculate angle between two vectors
        float angle(Vector3 const &vect) const {
            float result = 0.0f;

            Vector3 cros = { this->y*vect.z - this->z*vect.y, this->z*vect.x - this->x*vect.z, this->x*vect.y - this->y*vect.x };
            float len = sqrtf(cros.x*cros.x + cros.y*cros.y + cros.z*cros.z);
            float dot = (this->x*vect.x + this->y*vect.y + this->z*vect.z);
            result = atan2f(len, dot);

            return result;
        }

        // Divide vector by vector
        void divide(Vector3 const &vect) { *this = ::Vector3Divide(*this, vect); }

        // Get min value for each pair of components
        void min(Vector3 const &vect) { *this = ::Vector3Min(*this, vect); }

        // Get max value for each pair of components
        void max(Vector3 const &vect) { *this = ::Vector3Max(*this, vect); }

        // Negate provided vector (invert direction)
        void negate() { *this = ::Vector3Negate(*this); }

        // Calculate linear interpolation between two vectors
        void lerp(Vector3 const &vect, float amount) { *this = ::Vector3Lerp(*this, vect, amount); }

        // Compute barycenter coordinates (u, v, w) for point p with respect to triangle (a, b, c)
        // NOTE: Assumes P is on the plane of the triangle
        void barycenter(Vector3 const &a, Vector3 const &b, Vector3 const &c, Vector3 const &p) { *this = ::Vector3Barycenter(a, b, c, p); }

        //* Operators ------------------------------------------------------- //
        Vector3 operator*(Vector3 const vec) {
            return rl::Vector3(std::move(::Vector3Multiply(*this, vec))); }
        Vector3 operator+(Vector3 const vec) {
            return rl::Vector3(std::move(::Vector3Add(*this, vec))); }
        Vector3 operator-(Vector3 const vec) {
            return rl::Vector3(std::move(::Vector3Subtract(*this, vec))); }
        Vector3 operator/(Vector3 const vec) {
            if (vec.x == 0 || vec.y == 0 || vec.z == 0) return (*this);
            return { this->x / vec.x, this->y / vec.y, this->z / vec.z }; }


        Vector3 operator*(float const f) {
            return { this->x * f, this->y * f, this->z * f }; }
        Vector3 operator+(float const f) {
            return { this->x + f, this->y + f, this->z + f }; }
        Vector3 operator-(float const f) {
            return { this->x - f, this->y - f, this->z - f }; }
        Vector3 operator/(float const f) {
            if (f == 0) return (*this);
            return { this->x / f, this->y / f, this->z / f };
        }

        void operator=(::Vector3 const &vect)
        {
            this->x = vect.x;
            this->y = vect.y;
            this->z = vect.z;
        }

        void operator*=(Vector3 const vec) { *this = std::move(*this * vec); }
        void operator+=(Vector3 const vec) { *this = std::move(*this + vec); }
        void operator-=(Vector3 const vec) { *this = std::move(*this - vec); }
        void operator/=(Vector3 const &vec) { *this = std::move(*this / vec); }
        bool operator==(Vector3 const &vec) {
            return (this->x == vec.x && this->y == vec.y && this->z == vec.z); }
        bool operator!=(Vector3 const &vec) {
            return (!(*this == vec)); }

        void debug() const {
            std::cout << "Vector3 : " << this->debugString() << std::endl;
        }

        std::string debugString() const {
            return (std::to_string(this->x) + " " + std::to_string(this->y) + " " + std::to_string(this->z));
        }

    };
}
#endif /* !VECTOR3_HPP_ */
