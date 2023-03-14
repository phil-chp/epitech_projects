/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Ray
*/

#ifndef RAY_HPP_
    #define RAY_HPP_

    #include "Raylib-cpp.hpp"
    #include "Collisions/Collisions.hpp"
    #include "Vectors/Vector3.hpp"
    #include "Colors/Colors.hpp"
    #include "Models/Mesh/Mesh.hpp"
    #include "Models/Model/Model.hpp"
    #include "Matrix/Matrix.hpp"
    #include "Drawable/IDrawable.hpp"
    #include "Shapes/Shapes.hpp"

namespace rl {
    class Ray : public IDrawable, public ::Ray {
        public:
            Ray() : ::Ray{::Vector3{0, 0, 0}, ::Vector3{0, 0, 0}}, color(RL_RED) {};
            explicit Ray(::Ray const &ray) : ::Ray{ray} {};
            Ray(Vector3 const &position, Vector3 const &direction, Color const &color = RL_RED) : ::Ray{position, direction}, color(color) {};

            void operator=(::Ray const &ray) {
                this->position = ray.position;
                this->direction = ray.direction;
            }

            ~Ray() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Draw the ray
            void draw() const override;
            // Get collision info between ray and sphere
            RayCollision getCollisionSphere(Sphere const &sphere) const;
            // Get collision info between ray and box
            RayCollision getCollisionBox(BoundingBox const &box) const;
            // Get collision info between ray and mesh
            RayCollision getCollisionMesh(Mesh const &mesh) const;
            // Get collision info between ray and triangle
            RayCollision getCollisionTriangle(Triangle3D const &triangle) const;
            // Get collision info between ray and quad
            RayCollision getCollisionQuad(Vector3 const &p1, Vector3 const &p2, Vector3 const &p3, Vector3 const &p4) const;


            Color color;
    };
}

#endif /* !RAY_HPP_ */
