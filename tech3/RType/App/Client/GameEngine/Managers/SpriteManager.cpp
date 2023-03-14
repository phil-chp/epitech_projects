/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SpriteManager
*/


#include "GameEngine/Managers/SpriteManager.hpp"

template<>
void engine::SpriteManager::unload() {
    for (auto &sprite : this->_datas) {
        sprite.second.unload();
    }
}
