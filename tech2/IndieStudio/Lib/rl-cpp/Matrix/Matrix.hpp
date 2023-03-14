/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
    #define MATRIX_HPP_

    #include "Raylib-cpp.hpp"
    #include <iostream>
    #include "Vectors/Vector3.hpp"

namespace rl {
    class Matrix : public ::Matrix {
        public:
            Matrix() : ::Matrix{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} {};
            explicit Matrix(::Matrix const &matrix) : ::Matrix{matrix} {};
            explicit Matrix(float m) : ::Matrix{m, m, m, m, m, m, m, m, m, m, m, m, m, m, m, m} {};
            Matrix(float  m11, float  m12, float  m13, float  m14,
                   float  m21, float  m22, float  m23, float  m24,
                   float  m31, float  m32, float  m33, float  m34,
                   float  m41, float  m42, float  m43, float  m44)
                : ::Matrix{m11, m12, m13, m14,
                           m21, m22, m23, m24,
                           m31, m32, m33, m34,
                           m41, m42, m43, m44} {};
            ~Matrix() = default;

            //* Operators ------------------------------------------------------- //
            Matrix  operator+(Matrix const &mat) const {
                return Matrix(::std::move(::MatrixAdd(*this, mat))); }
            Matrix  operator-(Matrix const &mat) const {
                return Matrix(::std::move(::MatrixSubtract(*this, mat))); }
            Matrix  operator*(Matrix const &mat) const {
                return Matrix(::std::move(::MatrixMultiply(*this, mat))); }
            void    operator=(::Matrix const &matrix)
            {
                this->m0 = matrix.m0;
                this->m1 = matrix.m1;
                this->m2 = matrix.m2;
                this->m3 = matrix.m3;
                this->m4 = matrix.m4;
                this->m5 = matrix.m5;
                this->m6 = matrix.m6;
                this->m7 = matrix.m7;
                this->m8 = matrix.m8;
                this->m9 = matrix.m9;
                this->m10 = matrix.m10;
                this->m11 = matrix.m11;
                this->m12 = matrix.m12;
                this->m13 = matrix.m13;
                this->m14 = matrix.m14;
                this->m15 = matrix.m15;
            }
            void    operator+=(Matrix const &mat) { *this = ::std::move(*this + mat); }
            void    operator-=(Matrix const &mat) { *this = ::std::move(*this - mat); }
            void    operator*=(Matrix const &mat) { *this = ::std::move(*this * mat); }
            //TODO: add operator / and /= (check if method exists in raylibmath)

            //* Bult-in -------------------------------------------------------- //
            // Invert matrix
            void invert() { *this = ::MatrixInvert(*this); }

            // Transpose
            void transpose() { *this = ::MatrixTranspose(*this); }

            // Create rotation matrix from axis and angle. NOTE: Angle should be provided in radians
            void rotate(Vector3 const &axis, float  angle) { *this = ::MatrixRotate(axis, angle); }

            // Get x-rotation matrix (angle in radians)
            void rotateX(float  angle) { *this = ::MatrixRotateX(angle); }

            // Get y-rotation matrix (angle in radians)
            void rotateY(float  angle) { *this = ::MatrixRotateY(angle); }

            // Get z-rotation matrix (angle in radians)
            void rotateZ(float  angle) { *this = ::MatrixRotateZ(angle); }

            // Get xyz-rotation matrix (angles in radians)
            void rotateXYZ(Vector3 const &vect) { *this = ::MatrixRotateXYZ(vect); }

            // Get zyx-rotation matrix (angles in radians)
            void rotateZYX(Vector3 const &vect) { *this = ::MatrixRotateZYX(vect); }

            // Get scaling matrix
            void scale(Vector3 const &vect) { *this = ::MatrixScale(vect.x, vect.y, vect.z); }

            // Get perspective projection matrix
            void frustum(float  left, float  right, float  bottom, float  top, float  near, float  far) {
                *this = ::MatrixFrustum(left, right, bottom, top, near, far); }

            // Get perspective projection matrix. NOTE: Angle should be provided in radians
            void perspective(float  fov, float  aspect, float  near, float  far) {
                *this = ::MatrixPerspective(fov, aspect, near, far); }

            // Get camera look-at matrix (view matrix)
            void lookAt(Vector3 const &eye, Vector3 target, Vector3 const &up) {
                *this = ::MatrixLookAt(eye, target, up); }

            void debug() const {
                std::cout << "Matrix: " << std::endl;
                std::cout << "m0: " << this->m0 << std::endl;
                std::cout << "m1: " << this->m1 << std::endl;
                std::cout << "m2: " << this->m2 << std::endl;
                std::cout << "m3: " << this->m3 << std::endl;
                std::cout << "m4: " << this->m4 << std::endl;
                std::cout << "m5: " << this->m5 << std::endl;
                std::cout << "m6: " << this->m6 << std::endl;
                std::cout << "m7: " << this->m7 << std::endl;
                std::cout << "m8: " << this->m8 << std::endl;
                std::cout << "m9: " << this->m9 << std::endl;
                std::cout << "m10: " << this->m10 << std::endl;
                std::cout << "m11: " << this->m11 << std::endl;
                std::cout << "m12: " << this->m12 << std::endl;
                std::cout << "m13: " << this->m13 << std::endl;
                std::cout << "m14: " << this->m14 << std::endl;
                std::cout << "m15: " << this->m15 << std::endl;
            }
    };
}

#endif /* !MATRIX_HPP_ */
