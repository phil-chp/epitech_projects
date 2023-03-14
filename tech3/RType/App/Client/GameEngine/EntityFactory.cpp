/*
** EPITECH PROJECT, 2022
** RType
** File description:
** EntityFactory
*/

#include "GameEngine/EntityFactoryMap.hpp"

std::shared_ptr<engine::IEntity> engine::EntityFactory::createEngineEntity(engine::EntityType type) {
    return (engine::engineEntityMap.at(type)());
};

ecs::Entity engine::EntityFactory::createEntity(engine::EntityType type) {
    return (engine::entityMap.at(type)());
};
