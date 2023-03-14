/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
    #define AUDIO_HPP_

    #include "Raylib-cpp.hpp"
    #include "Sounds/Wave/Wave.hpp"
    #include "Sounds/Sound/Sound.hpp"
    #include <vector>
    #include <algorithm>

namespace rl {
    class Audio {
        public:
            // Initialize audio device and context
            static void initDevice();
            // Close the audio device and context
            static void close();
            // Check if audio device has been initialized successfully
            static bool isReady();
            // Set master volume (listener)
            static void setVolume(float volume);
            // Play a sound (using multichannel buffer pool)
            static void playSoundMulti(Sound const &sound);
            // Stop any sound playing (using multichannel buffer pool)
            static void stopSoundMulti();
            // Get number of sounds playing in the multichannel
            static int getSoundsPlaying();
            // Load samples data from wave as a float s array
            static float *loadWaveSamples(Wave const &wave);
            // Unload samples data loaded with LoadWaveSamples()
            static void unloadWaveSamples(std::vector<float> &samples);
    };
}

#endif /* !AUDIO_HPP_ */
