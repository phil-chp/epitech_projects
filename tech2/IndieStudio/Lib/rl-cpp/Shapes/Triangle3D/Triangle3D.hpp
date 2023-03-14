/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** TRIANGLE3D
*/

#ifndef TRIANGLE3D_HPP_
    #define TRIANGLE3D_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

namespace rl {
    class Triangle3D : public IDrawable {
        public:
            Triangle3D() : v1{0, 0, 0}, v2{0, 0, 0}, v3{0, 0, 0}, color{RL_RED} {}
            Triangle3D(Vector3 const &v1, Vector3 const &v2, Vector3 const &v3, Color const &tint = RL_RED) : v1{v1}, v2{v2}, v3{v3}, color{tint} {}
            ~Triangle3D() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                // Draw a color-filled triangle (vertex in counter-clockwise order!)
            void drawStrip(Vector2 *points, int pointsCount);                           // Draw a triangle strip defined by points

        //* Attribut --------------------------------------------------------- //

            Vector3 v1;
            Vector3 v2;
            Vector3 v3;
            Color color;
    };
}

#endif /* !TRIANGLE3D_HPP_ */
