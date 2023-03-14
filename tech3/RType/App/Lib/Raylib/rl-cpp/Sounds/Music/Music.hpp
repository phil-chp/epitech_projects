/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** MUSIC
*/

#ifndef MUSIC_HPP_
    #define MUSIC_HPP_


    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Sounds/ISound.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include <iostream>


namespace rl {
    class Music : public ::Music, public ASound {
        public:
            explicit Music(std::string const &filename, float volume = 0.5f)
                : ::Music{::LoadMusicStream(filename.c_str())}, ASound(volume), _isLoaded(true) {}

            void operator=(const ::Music& music) {
                this->stream = music.stream;
                this->frameCount = music.frameCount;
                this->looping = music.looping;
                this->ctxType = music.ctxType;
                this->ctxData = music.ctxData;
            };

        //* Custom ---------------------------------------------------------- //

            ~Music() {
                if (_isLoaded) {
                    this->unload();
                }
            }

        //* Built-in -------------------------------------------------------- //

            // ISOUND ------------------------------------------------------- //

            // Play a music
            void play() const final;
            // Unload audio stream and free memory
            void unload() final;
            // Update audio stream buffers with data
            void update(const void *data, int frameCount) const final;
            // Stop playing a music
            void stop() const final;
            // Pause a music
            void pause() const final;
            // Resume a paused music
            void resume() const final;
            // Check if a music is currently playing
            bool isPlaying() const final;

            // VOLUME ------------------------------------------------------- //

            // Updates the volume to the current value of volume
            void updateVolume() const final;

            // MUSIC -------------------------------------------------------- //

            // Load a music file
            void loadNew(Music const &music);
            // Seek to a specific time position in a music (in seconds)
            void seek(float position) const;
            // Get the length of a music (in seconds)
            float getLength() const;
            // Get the current position of the music (in seconds)
            float getPosition() const;

            bool isLoaded() const {
                return _isLoaded;
            }

            private:
                bool _isLoaded;

    };
}

#endif /* !MUSIC_HPP_ */
