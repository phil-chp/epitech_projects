/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** PLANE
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

namespace rl {
    class Plane : public IDrawable {
        public:
            Plane() : centerPos{0, 0, 0}, size{10, 10}, color{RL_RED} {}
            Plane(Vector3 const &Pos, Vector2 const &dimension, Color const &color = RL_RED) : centerPos(Pos), size(dimension), color(color) {}
            ~Plane() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                // Draw a Plane

        //* Attribut --------------------------------------------------------- //

            Vector3 centerPos;
            Vector2 size;
            Color color;
    };
}

#endif /* !PLANE_HPP_ */
