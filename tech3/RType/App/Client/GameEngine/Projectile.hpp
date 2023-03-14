/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Projectile
*/

#ifndef PROJECTILE_HPP_
    #define PROJECTILE_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "Utils/Vector2.hpp"
    

namespace engine {

class Projectile : public Entity {
    public:
        Projectile(::game::Vector2 pos = {0, 0}) : engine::Entity()
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Transform {
                    .position = pos,
                    .rotation = 0,
                    .scale = 0
            });
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RigidBody {
                    .velocity =  {500, 0},
                    .acceleration = {0, 0}
            });
        };
        ~Projectile() = default;
};
}
#endif