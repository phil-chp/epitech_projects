/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Alive
*/

#ifndef ALIVE_HPP_
    #define ALIVE_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"


namespace ecs {
    struct Alive {
        int hp;
        bool dead;
        bool shield;
    };
};

#endif /* !ALIVE_HPP_ */
