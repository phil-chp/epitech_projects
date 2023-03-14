/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
    #define ENTITYMANAGER_HPP_

    #include "ECS/Entity.hpp"
    #include "Errors/Errors.hpp"
    #include <algorithm>
    #include <iostream>
    #include <vector>
    #include <array>
    #include <queue>
    #include <bitset>

namespace ecs {
    class EntityManager {
    public:
        EntityManager() {
            for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
                this->_availableEntities.push(entity);
            }
        }
        ~EntityManager() = default;

        Entity createEntity() {
            if (this->_livingEntityCount >= MAX_ENTITIES) {
                throw ECSError("Too many entities in existence.");
            }
            Entity id = this->_availableEntities.front();
            this->_availableEntities.pop();
            this->_usedEntities.push_back(id);
            ++this->_livingEntityCount;
            return (id);
        }

        void destroyEntity(Entity entity) {
            if (entity >= MAX_ENTITIES) {
                throw ECSError("Entity out of range.");
            }
            this->_signatures[entity].reset();
            this->_usedEntities.erase(
                std::remove(this->_usedEntities.begin(), this->_usedEntities.end(), entity),
                this->_usedEntities.end()
            );
            this->_availableEntities.push(entity);
            --this->_livingEntityCount;
        }

        void clearEntities();

        void setSignature(Entity entity, Signature const &signature) {
            if (entity >= MAX_ENTITIES) {
                throw ECSError("Entity out of range.");
            }
            this->_signatures[entity] = signature;
        }

        Signature getSignature(Entity entity) {
            if (entity >= MAX_ENTITIES) {
                throw ECSError("Entity out of range.");
            }
            return this->_signatures[entity];
        }

    private:
        std::queue<Entity> _availableEntities{};
        std::vector<Entity> _usedEntities{};
        std::array<Signature, MAX_ENTITIES> _signatures{};
        std::uint32_t _livingEntityCount{};
    };
}

#endif /* !ENTITYMANAGER_HPP_ */
