/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** RigidBody
*/

#ifndef RIGID_BODY_HPP_
    #define RIGID_BODY_HPP_

    #include "Utils/Vector2.hpp"



namespace ecs {

    struct RigidBody {
        game::Vector2 velocity;
        game::Vector2 acceleration;
    };
}

#endif /* !RIGID_BODY_HPP_ */
