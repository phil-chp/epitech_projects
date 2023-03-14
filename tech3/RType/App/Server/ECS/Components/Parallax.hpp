/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
    #define PARALLAX_HPP_

    #include <vector>
    #include "ECS/Entity.hpp"
    #include "Utils/Vector2.hpp"

namespace ecs {
    struct Parallax {
        std::vector<Entity> layers;
        int finish;
        int size;
        unsigned int reps;
    };
}

#endif /* !PARALLAX_HPP_ */
