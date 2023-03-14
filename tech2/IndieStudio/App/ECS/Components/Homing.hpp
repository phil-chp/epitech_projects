/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Homing
*/

#ifndef HOMING_HPP_
    #define HOMING_HPP_

    #include "ECS/Component.hpp"

namespace ecs {
    struct Homing {
        Entity at;
        bool activ;
    };
}

#endif /* !HOMING_HPP_ */
