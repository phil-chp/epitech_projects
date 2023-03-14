/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** CollectibleSystem
*/

#include "CollectibleSystem.hpp"


void ecs::CollectibleSystem::update(float dt) const {
    std::vector<Entity> toRemove;
    (void)dt;
    for (ecs::Entity const &entity : entities) {
        Item &item = ecs::Coordinator::getInstance().getComponent<Item>(entity);

        if (item.taken) {

            rl::SoundManager::getInstance().getData(rl::SOUND_BONUS_PICKUP).play();
            item.applyEffect();
            item.dump();
            toRemove.push_back(entity);
        } else {
            continue;
        }
    }

    for (ecs::Entity entity : toRemove) {
        ecs::Coordinator::getInstance().destroyEntity(entity);
    }
}
