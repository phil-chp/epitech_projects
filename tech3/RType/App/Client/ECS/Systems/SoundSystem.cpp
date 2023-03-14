/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** SoundSystem
*/


#include "ECS/Systems/SoundSystem.hpp"
#include "ECS/Coordinator.hpp"

void ecs::SoundSystem::update(::engine::PollEvent &event) const {
    (void)event;
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    std::vector<ecs::Entity> toRm;
    for (ecs::Entity const &entity : this->entities) {
        SoundEffect &sound = coord.getComponent<ecs::SoundEffect>(entity);

        if (sound.isPlaying) {
            if (!sound.sound.isPlaying()) {
                if (sound.loop) {
                    sound.play();
                } else {
                    sound.isPlaying = false;
                    sound.repeat--;
                }
            }
        }
        if (!sound.isPlaying) {
            if (sound.repeat < 1 && !sound.loop) {
                toRm.push_back(entity);
            } else {
                sound.play();
                sound.isPlaying = true;
            }
        }
    }
    for (ecs::Entity entity : toRm) {
        coord.destroyEntity(entity);
    }
}
