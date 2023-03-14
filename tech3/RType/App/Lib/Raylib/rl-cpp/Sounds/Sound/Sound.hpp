/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Sound
*/

#ifndef SOUNDD_HPP_
    #define SOUNDD_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Sounds/ISound.hpp"
    #include "Lib/Raylib/rl-cpp/Sounds/Wave/Wave.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include "Lib/Raylib/rl-cpp/DataManager.hpp"

namespace rl {

    enum SoundType {
        SOUND_MISSING = -1,
        SOUND_BATTLE_COUNTDOWN,
        SOUND_BATTLE_END,
        SOUND_BATTLE_START,
        SOUND_BOMB_EXPLODE,
        SOUND_BOMB_FUSE,
        SOUND_BOMB_PLACE,
        SOUND_BONUS_PICKUP,
        SOUND_BUTTON_PRESS,
        SOUND_CRATE_BURN,
        SOUND_CRATE_DROP,
        SOUND_GAME_START,
        SOUND_PLAYER_DEATH,
        SOUND_PLAYER_SELECT_JOIN,
        SOUND_PLAYER_SELECT_READY,
        SOUND_PLAYER_STEP,
        BACKGROUND_MUSIC
    };

    struct SoundDatas {
        SoundType id;
        std::string const soundPath;
    };

    // const SoundDatas DEFAULT_SOUND = SoundDatas{SOUND_MISSING, "Assets/sounds/missing_sound.ogg"};

    class Sound : public ::Sound, public ASound {
        public:
            explicit Sound(rl::SoundType const &type = SOUND_MISSING);
            explicit Sound(std::string const &path)
                : ::Sound{::LoadSound(path.c_str())}, _isLoaded(true) {}
            explicit Sound(std::string const &path, float volume)
                : ::Sound{::LoadSound(path.c_str())}, ASound(volume), _isLoaded(true) {}
            explicit Sound(rl::Wave const &wave, float volume) : ::Sound{::LoadSoundFromWave(wave)}, ASound(volume), _isLoaded(true) {}

            void operator=(const ::Sound& sound) {
                this->stream = sound.stream;
                this->frameCount = sound.frameCount;
            }

        //* Custom ---------------------------------------------------------- //

            ~Sound() {
                // if (_isLoaded) {
                //     this->unload();
                // }
            }

        //* Built-in -------------------------------------------------------- //

            // ISOUND ------------------------------------------------------- //

            // Play a Sound
            void play() const final;
            // Unload audio stream and free memory
            void unload() final;
            // Update audio stream buffers with data
            void update(void const *data, int frameCount) const;
            // Stop playing a Sound
            void stop() const final;
            // Pause a Sound
            void pause() const final;
            // Resume a paused Sound
            void resume() const final;
            // Check if a Sound is currently playing
            bool isPlaying() const final;

            // VOLUME ------------------------------------------------------- //

            // Updates the volume to the current value of volume
            void updateVolume() const final;

            // SOUND -------------------------------------------------------- //

            // Load a sound file
            void loadNew(rl::Sound const &sound);

            bool isLoaded() const {
                return _isLoaded;
            }
        private:
            bool _isLoaded;

    };

    // typedef DataManager<Sound, SoundType> SoundManager;
}

#endif /* !SOUNDD_HPP_ */
