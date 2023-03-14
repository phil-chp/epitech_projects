/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** DestroySystem
*/

#include "DestroySystem.hpp"


void ecs::DestroySystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : entities) {
        Alive &alive = ecs::Coordinator::getInstance().getComponent<Alive>(entity);
        // Spawn &spawn = ecs::Coordinator::getInstance().getComponent<Spawn>(entity);
        Transform3D &transform = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);

        if (!alive.dead) continue;
        rl::SoundManager::getInstance().getData(rl::SOUND_CRATE_BURN).play();

        Entity itemSpawn = ecs::Coordinator::getInstance().createEntity();
        ecs::Coordinator::getInstance().addComponent(
            itemSpawn, ecs::Temporary {
                .delay = 0.90,
                .done = false
        });

        ecs::Coordinator::getInstance().addComponent(
            itemSpawn, ecs::Transform3D{
                .position = transform.position,
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(0.4, 0.4, 0.4)
        });

                   // bonus          // 0.2% chance of malus
        int type = std::rand() % 3 + (std::rand() % 5 == 0) * 3;
        ecs::Coordinator::getInstance().addComponent(
            itemSpawn, ecs::Spawn {
                .type = type,
                .rate = 50
        });
    };
}
