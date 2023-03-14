/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Shoot
*/

#ifndef SHOOT_HPP_
    #define SHOOT_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Components/Hitbox.hpp"
    #include "GameEngine/PollEvent.hpp"
    #include <vector>

namespace ecs {
enum AmmoType {
    AMO_MISSING = -1,
    AMO_DEFAULT = 0,
    AMO_LASER   = 1,
    AMO_CIRCLES = 2,
    AMO_BOUNCE  = 4,
    AMO_BOOM    = 8,
    AMO_HOME    = 16
};

enum ShootType {
    SHT_NOPE    = -1,
    SHT_AUTO    = 0,
    SHT_CONTROL = 1,
    SHT_AI      = 2
};

enum AimType {
    AIM_STRAIGHT = -1,
    AIM_ENT_TARGET,
    AIM_POINT_TARGET,
    AIM_PREDICT_TARGET
};

struct Shoot {
    ShootType shtType;
    AmmoType  amoType;
    AimType   aimType;
    float     rate;
    float     delay;
    short     lvl;
    bool      fired;
    game::Vector2 targetPoint;
    ecs::Entity target;
    std::vector<Entity> shots;
    Entity (*fire) (::game::Vector2 &, short, ::game::Vector2, ecs::CollisionType);
    CollisionType colType;

};
}

#endif /* !SHOOT_HPP_ */
