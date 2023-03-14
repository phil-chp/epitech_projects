/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
    #define TRANSFORM_HPP_

    #include "Raylib.hpp"

namespace ecs {
    struct Transform3D {
        rl::Vector3 position;
        rl::Vector3 rotation;
        rl::Vector3 scale;
    };

    struct Transform2D {
        rl::Vector2 position;
        rl::Vector2 rotation;
        rl::Vector2 scale;
    };
}

#endif /* !TRANSFORM_HPP_ */
