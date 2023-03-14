/*
** EPITECH PROJECT, 2022
** RType
** File description:
** FontManager
*/

#include "GameEngine/Managers/FontManager.hpp"

template<>
void engine::FontManager::unload() {
    for (auto &font : this->_datas) {
        font.second.unload();
    }
}
