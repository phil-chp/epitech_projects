/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** SpawnSystem
*/

#include "SpawnSystem.hpp"


void ecs::SpawnSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        Spawn &spawn = ecs::Coordinator::getInstance().getComponent<Spawn>(entity);
        Transform3D &trans = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);
        Temporary &temp = ecs::Coordinator::getInstance().getComponent<Temporary>(entity);
        // Alive &alive = ecs::Coordinator::getInstance().getComponent<Alive>(entity);

        if (!temp.done) continue;
        // if (!alive.dead) continue;

        if (std::rand() % 100 > spawn.rate) continue;
        rl::SoundManager::getInstance().getData(rl::SOUND_CRATE_DROP).play();

        Entity item = ecs::Coordinator::getInstance().createEntity();
        ecs::Coordinator::getInstance().addComponent(
            item, ecs::Temporary {
                .delay = 5,
                .done = false
        });
        ecs::Coordinator::getInstance().addComponent(
            item, ecs::Alive {
                .dead = false,
                .health = 1,
                .armor = 0
        });
        ecs::Coordinator::getInstance().addComponent(
            item, ecs::Transform3D{
                .position = trans.position,
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(0.4, 0.4, 0.4)
        });
        ecs::Coordinator::getInstance().addComponent(
            item, ecs::DrawableModel{
                .model = rl::Model(rl::MODEL_ITEM),
                .factor = 1.0f,
                .type = rl::MODEL_ITEM
        });
        ecs::Coordinator::getInstance().addComponent(
            item, ecs::RigidBody{
                .velocity = rl::Vector3(0.0f),
                .acceleration = rl::Vector3(0.0f),
                .type = ecs::CollisionType::ITEM,
                .grounded = true,
                .movable = false,
                .mass = 10
        });
        ecs::Coordinator::getInstance().addComponent(
            item, ecs::Item((ecs::ItemType) spawn.type));
    };
}
