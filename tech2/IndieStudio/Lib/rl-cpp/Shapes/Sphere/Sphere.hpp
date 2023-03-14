/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Drawable/IDrawable.hpp"

namespace rl {
    class Sphere : public IDrawable {
        public:
            Sphere() : position{0, 0, 0}, radius(5), color{RL_RED} {}
            Sphere(Vector3 const &pos, float rad, Color const &tint = RL_RED) : position{pos}, radius{rad}, color{tint} {}
            ~Sphere() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //
            void draw() const override;                                                  // Draw Sphere
            void drawWires(int rings, int slices) const;                        // Draw Sphere wires
            void drawEx(int rings, int slices);                           // Draw sphere with extended parameters


        //* Attribut --------------------------------------------------------- //

            Vector3 position;
            float radius;
            Color color;
    };
}

#endif /* !SPHERE_HPP_ */
