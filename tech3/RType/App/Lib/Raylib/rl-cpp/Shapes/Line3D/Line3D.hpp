/*
** EPITECH PROJECT, 2022
** RType
** File description:
** LINE3D
*/

#ifndef LINE3D_HPP_
    #define LINE3D_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"

namespace rl {
    class Line3D : public IDrawable {
        public:
            Line3D() : startPos{0, 0, 0} ,endPos{10, 10, 10}, color{RL_RED} {}
            Line3D(Vector3 const &sPos, Vector3 const &ePos, Color const &tint = RL_RED) : startPos(sPos), endPos(ePos), color(tint) {}
            ~Line3D() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                // Draw a color-filled triangle (vertex in counter-clockwise order!)

        //* Attribut --------------------------------------------------------- //

            Vector3 startPos;
            Vector3 endPos;
            Color color;
    };
}

#endif /* !LINE3D_HPP_ */
