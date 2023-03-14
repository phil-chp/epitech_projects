/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** LINE3D
*/

#ifndef LINE3D_HPP_
    #define LINE3D_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

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
