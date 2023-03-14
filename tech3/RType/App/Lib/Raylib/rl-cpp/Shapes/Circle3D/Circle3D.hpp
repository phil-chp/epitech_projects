/*
** EPITECH PROJECT, 2022
** RType
** File description:
** CIRCLE3D
*/

#ifndef CIRCLE3D_HPP_
    #define CIRCLE3D_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"

namespace rl {
    class Circle3D : public IDrawable {
        public:
            Circle3D() : center{0, 0, 0}, radius{0}, rotationAngle{0}, rotationAxis{0, 0, 0}, color{RL_RED} {}
            Circle3D(Vector3 const &origin, float rad, Vector3 const &rotAxis, float rotAngle, Color const &tint = RL_RED) : center(origin), radius(rad), rotationAngle(rotAngle), rotationAxis(rotAxis), color(tint) {}
            ~Circle3D() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                // Draw a color-filled triangle (vertex in counter-clockwise order!)
        //* Attribut --------------------------------------------------------- //

            Vector3 center;
            float radius;
            float rotationAngle;
            Vector3 rotationAxis;
            Color color;
        private:
    };
}

#endif /* !CIRCLE3D_HPP_ */
