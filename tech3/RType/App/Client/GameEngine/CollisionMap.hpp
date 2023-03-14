/*
** EPITECH PROJECT, 2022
** RType
** File description:
** CollisionMap
*/

#ifndef COLLISIONMAP_HPP_
    #define COLLISIONMAP_HPP_

    #include "GameEngine/Collision.hpp"

namespace engine {
    const std::map<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)> collisionMap = {
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_ENEMY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_ENEMY>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_PROJECTILE_ALLY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_PROJECTILE_ALLY>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_PROJECTILE_ENEMY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_PROJECTILE_ENEMY>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_WALL}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_WALL>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_PICKUP}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_PICKUP>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_TRIGGER}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_TRIGGER>),

        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_ENEMY, (int) ecs::CollisionType::COL_PLAYER}, &engine::Collision::collides<(int) ecs::CollisionType::COL_ENEMY, (int) ecs::CollisionType::COL_PLAYER>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_ENEMY, (int) ecs::CollisionType::COL_PROJECTILE_ALLY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_ENEMY, (int) ecs::CollisionType::COL_PROJECTILE_ALLY>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_ENEMY, (int) ecs::CollisionType::COL_WALL}, &engine::Collision::collides<(int) ecs::CollisionType::COL_ENEMY, (int) ecs::CollisionType::COL_WALL>),

        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_PLAYER}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_PLAYER>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_ENEMY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_ENEMY>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_PROJECTILE_ENEMY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_PROJECTILE_ENEMY>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_WALL}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_WALL>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_PICKUP}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ALLY, (int) ecs::CollisionType::COL_PICKUP>),

        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ENEMY, (int) ecs::CollisionType::COL_PLAYER}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ENEMY, (int) ecs::CollisionType::COL_PLAYER>),
        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PROJECTILE_ENEMY, (int) ecs::CollisionType::COL_PROJECTILE_ALLY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PROJECTILE_ENEMY, (int) ecs::CollisionType::COL_PROJECTILE_ALLY>),

        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_WALL, (int) ecs::CollisionType::COL_PROJECTILE_ALLY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_WALL, (int) ecs::CollisionType::COL_PROJECTILE_ALLY>),

        std::make_pair<std::pair<int, int>, void (*)(ecs::Entity, ecs::Entity, ::engine::PollEvent &)>({(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_SHIP_ALLY}, &engine::Collision::collides<(int) ecs::CollisionType::COL_PLAYER, (int) ecs::CollisionType::COL_SHIP_ALLY>)
    };
};
#endif /* !COLLISIONMAP_HPP_ */
