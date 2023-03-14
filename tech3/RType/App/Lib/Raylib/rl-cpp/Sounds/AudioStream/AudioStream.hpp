/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** AudioStream
*/

#ifndef AUDIOSTREAM_HPP_
    #define AUDIOSTREAM_HPP_


    #include "Lib/Raylib/rl-cpp/Sounds/Audio/Audio.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"

namespace rl {
    class AudioStream : public ::AudioStream, public ASound {
        public:
            AudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels, float volume = 0.5f)
                : ::AudioStream{::LoadAudioStream(sampleRate, sampleSize, channels)}, ASound(volume), _isLoaded(true) {};
            explicit AudioStream(::AudioStream const &audioStream, float volume = 0.5f)
                : ::AudioStream{audioStream}, ASound(volume), _isLoaded(true) {};

            void operator=(::AudioStream const &stream) {
                this->buffer = stream.buffer;
                this->sampleRate = stream.sampleRate;
                this->sampleSize = stream.sampleSize;
                this->channels = stream.channels;
            }

        //* Custom ---------------------------------------------------------- //

            ~AudioStream() {
                if (_isLoaded) {
                    this->unload();
                }
            }

        //* Built-in -------------------------------------------------------- //

            // ISOUND ------------------------------------------------------- //

            // Play a AudioStream
            void play() const final;
            // Unload audio stream and free memory
            void unload() final;
            // Update audio stream buffers with data
            void update(const void *data, int frameCount) const final;
            // Stop playing a AudioStream
            void stop() const final;
            // Pause a AudioStream
            void pause() const final;
            // Resume a paused AudioStream
            void resume() const final;
            // Check if a AudioStream is currently playing
            bool isPlaying() const final;

            // VOLUME ------------------------------------------------------- //

            // Updates the volume to the current value of volume
            void updateVolume() const final;

            // AUDIOSTREAM -------------------------------------------------- //

            // Load a AudioStream file
            void loadNew(AudioStream const &audioStream);
            // Check if any audio stream buffers requires refill
            bool isProcessed() const;

            bool isLoaded() const {
                return _isLoaded;
            }

        private:
            bool _isLoaded;



    };
}

#endif /* !AUDIOSTREAM_HPP_ */
