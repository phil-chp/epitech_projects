/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** CYLINDER
*/

#ifndef CYLINDER_HPP_
    #define CYLINDER_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

namespace rl {
    class Cylinder : public IDrawable {
        public:
            Cylinder() : position{0, 0, 0}, radiusTop(10), radiusBottom(10), height(10), slices(10), color{RL_RED} {}
            Cylinder(Vector3 const &pos, float radiusTop, float radiusBottom, float height, int slices, Color const &tint = RL_RED) : position(pos), radiusTop(radiusTop), radiusBottom(radiusBottom), height(height), slices(slices), color(tint) {}
            ~Cylinder() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                                                        // Draw Cylinder
            void drawEx(Vector3 const &startPos, Vector3 const &endPos, float startRadius, float endRadius, int sides);       // Draw a cylinder with base at startPos and top at endPos
            void drawWires();                                                                                   // Draw a cylinder/cone wires
            void drawWiresEx(Vector3 const &startPos, Vector3 const &endPos, float startRadius, float endRadius, int sides);  // Draw a cylinder wires with base at startPos and top at endPos

        //* Attribut --------------------------------------------------------- //

            Vector3 position;
            Vector3 size;
            float radiusTop;
            float radiusBottom;
            float height;
            int slices;
            Color color;
    };
}

#endif /* !CYLINDER_HPP_ */
