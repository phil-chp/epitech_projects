/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** SETTINGS
*/

#ifndef SETTINGS_MANAGER_HPP_
    #define SETTINGS_MANAGER_HPP_
    #include "SettingsManager.hpp"

SettingsManager::SettingsManager() {
    this->musicVolume = 60;
    this->soundVolume = 60;
    this->resolution.x = rl::Window::getInstance().getWidth();
    this->resolution.y = rl::Window::getInstance().getHeight();
    this->playersKey.push_back({rl::qwerAzerty[rl::KEY_W], rl::qwerAzerty[rl::KEY_S], rl::qwerAzerty[rl::KEY_A], rl::qwerAzerty[rl::KEY_D], rl::qwerAzerty[rl::KEY_E]});
    this->playersKey.push_back({rl::qwerAzerty[rl::KEY_UP], rl::qwerAzerty[rl::KEY_DOWN], rl::qwerAzerty[rl::KEY_LEFT], rl::qwerAzerty[rl::KEY_RIGHT], rl::qwerAzerty[rl::KEY_ENTER]});
    this->playersKey.push_back({rl::qwerAzerty[rl::KEY_T], rl::qwerAzerty[rl::KEY_G], rl::qwerAzerty[rl::KEY_F], rl::qwerAzerty[rl::KEY_H], rl::qwerAzerty[rl::KEY_Y]});
    this->playersKey.push_back({rl::qwerAzerty[rl::KEY_O], rl::qwerAzerty[rl::KEY_L], rl::qwerAzerty[rl::KEY_K], rl::qwerAzerty[rl::KEY_SEMICOLON], rl::qwerAzerty[rl::KEY_P]});
}

void SettingsManager::setSoundVolume(uint8_t volume) {
    this->soundVolume = (volume > 100 ? 100 : volume);
}

void SettingsManager::setMusicVolume(uint8_t volume) {
    this->musicVolume = (volume > 100 ? 100 : volume);
}

void SettingsManager::setResolution(rl::Vector2 const &volume) {
    this->resolution = volume;
}

void SettingsManager::setPlayersKey(std::vector<std::array<rl::KeyboardKeys, 5> > const &playersKey) {
    this->playersKey = playersKey;
}

void SettingsManager::setKey(uint8_t index, KeyPlayer touch, rl::KeyboardKeys const &key) {
    this->playersKey[index][touch] = key;
}

uint8_t SettingsManager::getSoundVolume() const {
    return this->soundVolume;
}

uint8_t SettingsManager::getMusicVolume() const {
    return this->musicVolume;
}

rl::Vector2 const &SettingsManager::getResolution() const {
    return this->resolution;
}

std::vector<std::array<rl::KeyboardKeys, 5> > const &SettingsManager::getPlayersKey() const {
    return this->playersKey;
}

std::array<rl::KeyboardKeys, 5> const &SettingsManager::getPlayerKeys(uint8_t index) const {
    return this->playersKey[index];
}

#endif
