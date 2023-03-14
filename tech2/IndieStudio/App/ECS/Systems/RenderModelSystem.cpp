/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** RenderSystem
*/

#include "RenderSystem.hpp"


void ecs::RenderModelSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        DrawableModel &drawable = ecs::Coordinator::getInstance().getComponent<DrawableModel>(entity);
        Transform3D &trans = ecs::Coordinator::getInstance().getComponent<Transform3D>(entity);

        // rl::ModelAnimationManager::getInstance().getData(drawable.model.getAnimType()).animIncrement(
        //     0,
        //     drawable.model);
        if (drawable.type == rl::MODEL_BOMB) {
            rl::ModelAnimationManager::getInstance().getData(rl::ANIM_BOMB).animIncrement(
                0,
                drawable.model);
        }

        drawable.draw(trans.position, trans.rotation, trans.scale.x);
    }
}
