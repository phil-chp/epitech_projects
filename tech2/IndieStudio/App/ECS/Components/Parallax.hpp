/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** WIDGET
*/

#ifndef PARALLAX_HPP_
    #define PARALLAX_HPP_

    #include "Raylib.hpp"
    #include <array>

namespace ecs {
    struct Parallax {
        float scrollingBack;
        float scrollingMid;
        float scrollingFore;
    };
}

#endif /* !PARALLAX_HPP_ */
