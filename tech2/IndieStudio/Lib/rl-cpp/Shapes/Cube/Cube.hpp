/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Cube
*/

#ifndef CUBE_HPP_
    #define CUBE_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

namespace rl {
    class Cube : public IDrawable {
        public:
            Cube() : position{0, 0, 0}, size{10, 10, 10}, color{RL_WHITE} {}
            Cube(Vector3 const &pos) : position{pos}, size{10, 10, 10}, color{RL_WHITE} {}
            Cube(Vector3 const &pos, Vector3 const &dimension, Color const &tint = RL_WHITE) : position{pos}, size{dimension}, color{tint} {}
            ~Cube() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                  // Draw cube
            void drawWires();                                                            // Draw cube wires
            void drawTexture(Texture2D const &texture);                                  // Draw cube textured
            void drawTextureRec(Texture2D const &texture, Rectangle const &source);      // Draw cube with a region of a texture

        //* Attribut --------------------------------------------------------- //
            Vector3 position;
            Vector3 size;
            Color color;
    };
}

#endif /* !CUBE_HPP_ */
