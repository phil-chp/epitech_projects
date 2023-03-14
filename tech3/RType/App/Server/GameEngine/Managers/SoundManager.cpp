/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SoundManager.cpp
*/

#include "GameEngine/Managers/SoundManager.hpp"

template<>
void engine::SoundManager::unload() {
    for (auto &font : this->_datas) {
        font.second.unload();
    }
}
