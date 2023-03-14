/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Controlled
*/

#ifndef CONTROLLED_HPP_
    #define CONTROLLED_HPP_

    #include "Raylib.hpp"

namespace ecs {
    struct Controlled {
        // KeyboardKey up;
        rl::KeyboardKeys left;
        rl::KeyboardKeys right;
        rl::KeyboardKeys front;
        rl::KeyboardKeys back;

        rl::KeyboardKeys place;
        // KeyboardKey interact;
    };
}

#endif /* !CONTROLLED_HPP_ */
