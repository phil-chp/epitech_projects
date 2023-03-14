/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** EntityManager
*/

#include "EntityManager.hpp"
#include "Coordinator.hpp"

void ecs::EntityManager::clearEntities() {
    std::vector<ecs::Entity> usedEntities;
    std::copy(this->_usedEntities.begin(), this->_usedEntities.end(), std::back_inserter(usedEntities));
    for (ecs::Entity &entity : usedEntities) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}