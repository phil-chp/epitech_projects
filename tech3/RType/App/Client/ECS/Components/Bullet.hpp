/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Bullet
*/

#ifndef BULLET_HPP_
#define BULLET_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"
    #include "GameEngine/PollEvent.hpp"


namespace ecs {
    struct Bullet {
        void (*update) (ecs::Entity, ::engine::PollEvent &);
    };
};

#endif /* !BULLET_HPP_ */
