/*
** EPITECH PROJECT, 2022
** RType
** File description:
** IEnemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_
    #include "GameEngine/Entity.hpp"

namespace engine {
namespace rtype {
class Enemy : public ::engine::Entity {
    public:
        Enemy() : ::engine::Entity()
        {

        }
        ~Enemy() = default;
};
}
}


#endif /* !IENEMY_HPP_ */
