/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
    #define BOMB_HPP_

    #include "ECS/Entity.hpp"
    #include <memory>
    #include <mutex>

namespace ecs {
    struct Bomb { // TODO: Explosive
        int size;
        Entity entity;
    };
}

#endif /* !BOMB_HPP_ */
