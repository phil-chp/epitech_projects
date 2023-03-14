/*
** EPITECH PROJECT, 2022
** RType
** File description:
** GRID
*/

#ifndef GRID_HPP_
    #define GRID_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"

namespace rl {
    class Grid : public IDrawable {
        public:
            Grid() : slices(10), spacing(10) {};
            Grid(int Slices, float Spacing) :  slices(Slices), spacing(Spacing) {};
            ~Grid() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                // Draw a Grid

        //* Attribut --------------------------------------------------------- //

            int slices;
            float spacing;

    };
}

#endif /* !GRID_HPP_ */
