/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** CollisionSystem
*/

#ifndef COLLISIONBSYSTEM_HPP_
    #define COLLISIONBSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"
    #include <utility>

namespace ecs {
    class CollisionSystem : public ASystem {
        public:
            CollisionSystem() = default;
            ~CollisionSystem() = default;

            void update(float dt) const final;

            // w/  RigidBody
        private:
            void getBlocked(Transform3D &t1, Transform3D &t2, RigidBody &body, float dt) const;
            void hitDetection(Entity const &e1, Entity const &e2, CollisionType type) const;
            void hitSpread(Entity const &e1, Transform3D &t1, RigidBody &body) const;
            // w/o RigidBody
    };
}
#endif /* !COLLISIONBSYSTEM_HPP_ */
