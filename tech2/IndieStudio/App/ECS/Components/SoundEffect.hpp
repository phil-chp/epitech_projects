/*
** EPITECH PROJECT, 2022
** IndieStudio (Workspace)
** File description:
** Sound
*/

#ifndef SOUND_EFFECT_HPP_
    #define SOUND_EFFECT_HPP_

    #include "Raylib.hpp"

namespace ecs {
    struct SoundEffect {
        void play() const {
            this->sound.play();
        }

        rl::Sound sound;
    };
}

#endif /* !SOUND_EFFECT_HPP_ */
