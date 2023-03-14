/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** SETTINGS
*/

#ifndef B_YEP_400_NCE_4_1_INDIESTUDIO_ANTHONY_GHIZZO_SETTINGSMANAGER_HPP
#define B_YEP_400_NCE_4_1_INDIESTUDIO_ANTHONY_GHIZZO_SETTINGSMANAGER_HPP

#include "Raylib.hpp"
#include <vector>
#include <array>

enum KeyPlayer {
    KEY_P_UP,
    KEY_P_DOWN,
    KEY_P_LEFT,
    KEY_P_RIGHT,
    KEY_P_BOMB
};

class SettingsManager {
    public:
        static SettingsManager &getInstance() {
            static SettingsManager instance;
            return instance;
        }
        SettingsManager(SettingsManager const&) = delete;
        void operator=(SettingsManager const&) = delete;

        void setSoundVolume(uint8_t volume);
        void setMusicVolume(uint8_t volume);
        void setResolution(rl::Vector2 const &volume);
        void setPlayersKey(std::vector<std::array<rl::KeyboardKeys, 5> > const &playersKey);
        void setKey(uint8_t indexPlayer, KeyPlayer touch, rl::KeyboardKeys const &key);

        uint8_t getSoundVolume() const;
        uint8_t getMusicVolume() const;
        rl::Vector2 const &getResolution() const;
        std::vector<std::array<rl::KeyboardKeys, 5> > const &getPlayersKey() const;
        std::array<rl::KeyboardKeys, 5> const &getPlayerKeys(uint8_t index) const;
    private:
        SettingsManager();
        std::vector<std::array<rl::KeyboardKeys, 5> > playersKey;
        rl::Vector2 resolution;
        uint8_t soundVolume;
        uint8_t musicVolume;
};

#endif //B_YEP_400_NCE_4_1_INDIESTUDIO_ANTHONY_GHIZZO_SETTINGSMANAGER_HPP
