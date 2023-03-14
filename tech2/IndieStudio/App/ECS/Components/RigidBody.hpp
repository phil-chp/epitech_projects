/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** RigidBody
*/

#ifndef RIGID_BODY_HPP_
    #define RIGID_BODY_HPP_

    #include "Raylib.hpp"

namespace ecs {
    enum CollisionType {
        SPREAD,
        HIT,
        ITEM,
        PLAYER,
        BOMB,
        PASS_BOMB,
        CRATE,
        GHOST,
        SOLID
    };

    // TODO: cut this down into a RigidBody and a Playable component
    struct RigidBody {
        rl::Vector3 velocity;
        rl::Vector3 acceleration;
        CollisionType type;
        bool grounded;
        bool movable;
        int mass; // -> un int > 0 qui sera jamais > bcp, on va dire MAX_MASS = 1000
    };
}

#endif /* !RIGID_BODY_HPP_ */
