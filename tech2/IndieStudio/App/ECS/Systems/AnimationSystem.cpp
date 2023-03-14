/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** AnimationSystem
*/

#include "AnimationSystem.hpp"


void ecs::AnimationSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        DrawableModel &drawable = ecs::Coordinator::getInstance().getComponent<DrawableModel>(entity);
        Controlled &control = ecs::Coordinator::getInstance().getComponent<Controlled>(entity);
        Alive &body = ecs::Coordinator::getInstance().getComponent<Alive>(entity);
        bool keyDown = (rl::Keyboard::isKeyDown(control.front) || rl::Keyboard::isKeyDown(control.back) || rl::Keyboard::isKeyDown(control.left) || rl::Keyboard::isKeyDown(control.right));

        char animation = (body.dead ? 2 : (keyDown == false ? 1 : 0));
        rl::ModelAnimationManager::getInstance().getData(rl::ANIM_PLAYER).animIncrement(animation, drawable.model);
    }
}
