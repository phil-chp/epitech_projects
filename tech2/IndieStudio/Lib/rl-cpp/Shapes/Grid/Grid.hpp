/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** GRID
*/

#ifndef GRID_HPP_
    #define GRID_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

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
