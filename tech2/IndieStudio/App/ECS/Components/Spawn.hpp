/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** Spawn
*/

#ifndef SPAWN_HPP_
    #define SPAWN_HPP_

    #include "Raylib.hpp"
    #include <cstdlib>

namespace ecs {
    struct Spawn {
        int type;
        int rate;
    };
}
#endif /* !SPAWN_HPP_ */
