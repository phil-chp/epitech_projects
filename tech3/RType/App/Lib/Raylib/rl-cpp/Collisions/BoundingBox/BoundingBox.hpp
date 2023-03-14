/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** BoundingBox
*/

#ifndef BOUNDINGBOX_HPP_
    #define BOUNDINGBOX_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vectors.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Shapes/Shapes.hpp"

namespace rl {
    class BoundingBox : public ::BoundingBox {
        public:
            BoundingBox() : ::BoundingBox{::Vector3{0, 0, 0}, ::Vector3{0, 0, 0}} {};
            BoundingBox(Vector3 const &min, Vector3 const &max) : ::BoundingBox{min, max} {};
            explicit BoundingBox(::BoundingBox const &boundingBox) : ::BoundingBox{boundingBox} {};

            void operator=(::BoundingBox const &boundingBox) {
                this->min = boundingBox.min;
                this->max = boundingBox.max;
            }

            ~BoundingBox() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Check collision between two bounding boxes
            bool checkCollisionBoxes(BoundingBox const &box) const;
            // Check collision between box and sphere
            bool checkCollisionBoxSphere(Sphere const &sphere) const;

    };
}

#endif /* !BOUNDINGBOX_HPP_ */
