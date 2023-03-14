/*
** EPITECH PROJECT, 2022
** RType
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "Utils/Vector2.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Components/Shoot.hpp"
#include "GameEngine/PollEvent.hpp"

namespace ecs
{
    enum AIMoveType
    {
        AIMOV_NONE = -1,
        AIMOV_STATIC = 0,
        AIMOV_STRAIGHT = 1
    };

    struct AI
    {
        struct
        {
            AIMoveType type;
            struct
            {
                float a;
                float b;
            } val;
            Entity target;
            game::Vector2 targetPoint;
            bool set;
            void (*updateMove) (ecs::Entity, float);
        } move;
        struct
        {
            AimType aimType;
            Entity target;
            game::Vector2 targetPoint;
            bool set;
            void (*updateBullet) (ecs::Entity, ::engine::PollEvent &);
        } shoot;
        float lifeTime;

        void targetMoveAt(game::Vector2 pos)
        {
            this->move.targetPoint = pos;
        }
        void targetMoveIt(Entity entity)
        {
            this->move.target = entity;
        }
        void targetShootAt(game::Vector2 pos)
        {
            this->shoot.targetPoint = pos;
        }
        void targetShootIt(Entity entity)
        {
            this->shoot.target = entity;
        }
    };
};

#endif /* !AI_HPP_ */
