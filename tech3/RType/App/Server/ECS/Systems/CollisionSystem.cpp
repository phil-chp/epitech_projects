/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** CollisionSystem
*/

#include "ECS/Systems/CollisionSystem.hpp"
#include "GameEngine/GridCollision.hpp"
#include "GameEngine/Collision.hpp"
#include "GameEngine/Managers/LevelManager.hpp"
#include "GameEngine/LinkerEntities.hpp"

void ecs::CollisionSystem::update(::engine::PollEvent &event) const
{
    std::vector<ecs::Entity> toRm;

    for (ecs::Entity const &entity : this->entities) {
        Hitbox &hitbox = Coordinator::getInstance().getComponent<Hitbox>(entity);
        Transform &transform = Coordinator::getInstance().getComponent<Transform>(entity);
        hitbox.bounds->pos.x = transform.position.x;
        hitbox.bounds->pos.y = transform.position.y;
        hitbox.rect.x = transform.position.x;
        hitbox.rect.y = transform.position.y;
    }
    ::engine::GridSystem::getInstance().populateCells(this->entities);
    // ::engine::GridSystem::getInstance().dump();
    ::engine::GridSystem::getInstance().getCollisions();
    const engine::Square &lifeZone = engine::LevelManager::getInstance().getLifeZone();
    for (ecs::Entity const &entity : this->entities) {
        Hitbox &hitbox = Coordinator::getInstance().getComponent<Hitbox>(entity);
        if (!lifeZone.collides(hitbox.bounds)) {
            toRm.push_back(entity);
            continue;
        }
        // hitbox.rect.draw();
        for (ecs::Entity &ent : hitbox.collidesWith) {
            if (std::find(hitbox.collidedWith.begin(), hitbox.collidedWith.end(), ent) != hitbox.collidedWith.end())
                continue;
            Hitbox &otrHitbox = Coordinator::getInstance().getComponent<Hitbox>(ent);
            if (std::find(otrHitbox.collidedWith.begin(), otrHitbox.collidedWith.end(), entity) != otrHitbox.collidedWith.end())
                continue;
            const int otrType = (const int) otrHitbox.colType;
            otrHitbox.collidedWith.push_back(entity);
            hitbox.collidedWith.push_back(ent);
            // std::cout << entity << "collides with " << ent << std::endl;
            if (hitbox.invFrames > 0) {
                hitbox.invFrames -= 1;
            } else {
                const int type = (const int) hitbox.colType;

                ::engine::Collision::collide(entity, ent, type, otrType, event);
            }

        }
        hitbox.collidesWith.clear();
        hitbox.collidedWith.clear();
    }

    for (ecs::Entity entity :toRm) {
        ::engine::LinkerEntities::getInstance().removeEntity(entity);
    }

}
