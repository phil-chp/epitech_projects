/*
** EPITECH PROJECT, 2022
** RType
** File description:
** POINT3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"

namespace rl {
    class Point3D : public IDrawable {
        public:
            Point3D() : position{0, 0, 0}, color{RL_RED} {}
            Point3D(Vector3 const &pos, Color const &tint = RL_RED) : position{pos}, color{tint} {}
            ~Point3D() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                // Draw a color-filled triangle (vertex in counter-clockwise order!)

        //* Attribut --------------------------------------------------------- //

            Vector3 position;
            Color color;
    };
}

#endif /* !POINT3D_HPP_ */
