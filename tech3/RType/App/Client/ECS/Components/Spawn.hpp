/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Spawn
*/

#ifndef Spawn_HPP_
    #define Spawn_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/Components/AI.hpp"


namespace ecs {

    enum SpawnFluct {
        NO_INVERT    = -1,
        VERT_INVERT  = 0,
        HORI_INVERT  = 1,
        RANDOM_FLUCT = 2
    };

    struct Spawn {
        int type;
        int rate;
        unsigned int repeat;
        bool timed;
        float delay;
        bool lifed;

        // bool intelligent;
        // ecs::AI ai;
        ecs::Entity (*spawn) (ecs::Entity);
    };
};

#endif /* !Spawn_HPP_ */
