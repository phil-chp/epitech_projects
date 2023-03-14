/*
** EPITECH PROJECT, 2022
** IndieStudio (Workspace)
** File description:
** PlaySoundSystem
*/

#include "PlaySoundSystem.hpp"

void ecs::PlaySoundSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        SoundEffect &sound = ecs::Coordinator::getInstance().getComponent<ecs::SoundEffect>(entity);

        sound.play();
    }
}
