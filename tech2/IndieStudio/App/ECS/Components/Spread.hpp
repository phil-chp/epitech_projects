/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** RigidBody
*/

#ifndef SPREAD_HPP_
    #define SPREAD_HPP_

    #include "Raylib.hpp"

namespace ecs {
    struct Spread {
        int fire;
        rl::Vector3 posX;
        rl::Vector3 posZ;
        int sizeXPos;
        int sizeZPos;
        int sizeXNeg;
        int sizeZNeg;
    };
}

#endif /* !SPREAD_HPP_ */
