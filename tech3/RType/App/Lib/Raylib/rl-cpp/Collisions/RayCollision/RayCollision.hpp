/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** RayCollision
*/

#ifndef RAYCOLLISION_HPP_
    #define RAYCOLLISION_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"

namespace rl {
    class RayCollision : public ::RayCollision {
        public:
            RayCollision(bool const &hit, float distance, Vector3 const &point, Vector3 const &normal)
                : ::RayCollision{hit, distance, point, normal} {};
            explicit RayCollision(::RayCollision const &rayCollision) : ::RayCollision{rayCollision} {};

            void operator=(::RayCollision const &rayCollision) {
                this->hit = rayCollision.hit;
                this->distance = rayCollision.distance;
                this->point = rayCollision.point;
                this->normal = rayCollision.normal;
            }

            ~RayCollision() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

    };
}

#endif /* !RAYCOLLISION_HPP_ */
