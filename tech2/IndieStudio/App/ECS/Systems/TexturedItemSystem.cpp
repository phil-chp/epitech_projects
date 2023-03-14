/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** TexturedItemSystem
*/

#include "TexturedItemSystem.hpp"


void ecs::TexturedItemSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : entities) {
        Item &item = ecs::Coordinator::getInstance().getComponent<Item>(entity);
        DrawableModel &drawable = ecs::Coordinator::getInstance().getComponent<DrawableModel>(entity);

        if (drawable.type != rl::MODEL_ITEM) continue;
        // TODO: copy of the same model each time, so all textures change
        static TextureMap const textureMap = this->getTextureMap();
        drawable.model.setMaterialTexture(rl::MAT_DIFFUSE, (rl::TextureType)textureMap.at(item.type));
    }
}

ecs::TextureMap const ecs::TexturedItemSystem::getTextureMap() const {
    return {
        std::make_pair(ecs::BOMB_UP,    rl::TEXTURE_ITEM_BOMB_UP),
        std::make_pair(ecs::SPEED_UP,   rl::TEXTURE_ITEM_SPEED_UP),
        std::make_pair(ecs::FIRE_UP,    rl::TEXTURE_ITEM_FIRE_UP),
        std::make_pair(ecs::BOMB_DOWN,  rl::TEXTURE_ITEM_BOMB_DOWN),
        std::make_pair(ecs::SPEED_DOWN, rl::TEXTURE_ITEM_SPEED_DOWN),
        std::make_pair(ecs::FIRE_DOWN,  rl::TEXTURE_ITEM_FIRE_DOWN)
    };
}
