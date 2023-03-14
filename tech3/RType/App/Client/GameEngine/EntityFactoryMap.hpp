/*
** EPITECH PROJECT, 2022
** RType
** File description:
** EntityFactoryMap
*/

#include "GameEngine/EntityFactory.hpp"

namespace engine {
    const std::map<engine::EntityType, ecs::Entity(*)()> entityMap = {
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER1,        &engine::rtype::ShipPlayer<0>::construct),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER2,        &engine::rtype::ShipPlayer<1>::construct),
        // std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER3,        &engine::rtype::ShipPlayer<2>::construct),
        // std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER4,        &engine::rtype::ShipPlayer<3>::construct),
        // std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER1_ATTACH, &engine::rtype::AttachShip<0>::construct),
        // std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER2_ATTACH, &engine::rtype::AttachShip<1>::construct),
        // std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER3_ATTACH, &engine::rtype::AttachShip<2>::construct),
        // std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAYER4_ATTACH, &engine::rtype::AttachShip<3>::construct),
        // std::make_pair<EntityType, ecs::Entity(*)()>(ENEMY,          &engine::rtype::),
        // std::make_pair<EntityType, ecs::Entity(*)()>(BULLET,         &engine::rtype::),
        // std::make_pair<EntityType, ecs::Entity(*)()>(WALL,           &engine::rtype::),
        // std::make_pair<EntityType, ecs::Entity(*)()>(POWERUP,        &engine::rtype::),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(PLAY_BUTTON,    &engine::rtype::PlayButton::construct),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(SPACE_PARALLAX, &engine::rtype::SpaceParallax::construct),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(ENEMY1, &engine::rtype::SpaceShipEnemy::construct),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(SPOT_SHAD, &engine::rtype::LightShader::construct),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(COLOR_SHAD, &engine::rtype::ColorShader::construct),
        std::make_pair<engine::EntityType, ecs::Entity(*)()>(WAVE_SHAD, &engine::rtype::WaveShader::construct)
    };

    const std::map<engine::EntityType, std::shared_ptr<IEntity>(*)()> engineEntityMap = {
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(PLAYER1,        &engine::EntityFactory::createShipPlayer1),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(PLAYER2,        &engine::EntityFactory::createShipPlayer2),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(PLAYER3,        &engine::EntityFactory::createShipPlayer3),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(PLAYER4,        &engine::EntityFactory::createShipPlayer4),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(PLAY_BUTTON,    &engine::EntityFactory::createPlayButton),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(SPACE_PARALLAX, &engine::EntityFactory::createSpaceParallax),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(ENEMY1, &engine::EntityFactory::createSpaceEnemy),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(SPOT_SHAD, &engine::EntityFactory::createLightShader),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(COLOR_SHAD, &engine::EntityFactory::createColorShader),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(WAVE_SHAD, &engine::EntityFactory::createWaveShader),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(BERIC, &engine::EntityFactory::createBeric),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(CONTREUNO, &engine::EntityFactory::createContreUno),
        std::make_pair<engine::EntityType, std::shared_ptr<IEntity>(*)()>(FEUR, &engine::EntityFactory::createFeur)

    };
}
