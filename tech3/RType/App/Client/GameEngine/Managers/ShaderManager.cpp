/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ShaderManager
*/


#include "GameEngine/Managers/ShaderManager.hpp"

template<>
void engine::ShaderManager::unload() {
    for (auto &shader : this->_datas) {
        shader.second.unload();
    }
}
