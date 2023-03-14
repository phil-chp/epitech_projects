/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** POINT3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

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
