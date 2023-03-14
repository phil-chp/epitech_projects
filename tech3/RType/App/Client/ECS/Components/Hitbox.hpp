/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Hitbox
*/

#ifndef HITBOX_HPP_
    #define HITBOX_HPP_

    #include "ECS/Entity.hpp"
    #include <vector>
    #include "GameEngine/Shape.hpp"
    #include "Lib/Raylib/rl-cpp/Shapes/Shapes.hpp"


namespace ecs {
    enum HitBoxType {
        BOX_NONE            =-1,
        BOX_SQUARE          = 0,
        BOX_CIRCULAR        = 1,
        BOX_AMALGAM_SQUARE  = 2,
        BOX_AMALGAM_CIRCLE  = 3
    };


    enum CollisionType {
        COL_NONE = 0,
        COL_WALL,
        COL_PLAYER,
        COL_ENEMY,
        COL_PROJECTILE_ALLY,
        COL_PROJECTILE_ENEMY,
        COL_PICKUP,
        COL_TRIGGER,
        COL_SHIP_ALLY
    };

    struct Hitbox {
        HitBoxType type;
        std::shared_ptr<engine::AShape> bounds;
        std::vector<Entity> collidesWith;
        std::vector<Entity> collidedWith;
        CollisionType colType;
        int invFrames = 0;
        rl::Rectangle rect;
    };


};

#endif /* !HITBOX_HPP_ */
