/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** SoundManager
*/

#ifndef SOUNDMANAGER_HPP_
    #define SOUNDMANAGER_HPP_

    #include "Utils/DataManager.hpp"
    #include "Lib/Raylib/rl-cpp/Sounds/Sounds.hpp"

namespace engine {
    enum SoundType {
        SO_MISSING = -1,
        SO_DEFAULT = 0,
        SO_BG_MUS = 1,
        SO_BOSS1,
        SO_BG_MENU,
        SO_RAY_GUN,
        SO_BASIC_SHOT,
        SO_DEATH_SE,
        SO_LOSE_SCREEN,
        SO_PICK_UP_SE,
        SO_SHIELD_SE,
        SO_WIN_SCREEN
    };

typedef DataManager<::rl::Sound, SoundType> SoundManager;

// typedef DataManager<::lib::sdl::Sound, SoundType> TextureManager;
} // namespace engine

#endif /* !SOUNDMANAGER_HPP_ */
