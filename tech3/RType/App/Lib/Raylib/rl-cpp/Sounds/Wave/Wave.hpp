/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Wave
*/

#ifndef WAVE_HPP_
    #define WAVE_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Sounds/ISound.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include <iostream>

namespace rl {
    class Wave : public ::Wave {
        public:
            explicit Wave(std::string const &fileName) : ::Wave{::LoadWave(fileName.c_str())}, _isLoaded(true) {}
            // TODO: unsigned char const * ? any better idea, unsigned might be problematic
            Wave(std::string const &fileType, unsigned char const *fileData, int dataSize)
                : ::Wave{::LoadWaveFromMemory(fileType.c_str(), fileData, dataSize)}, _isLoaded(true) {}

            void operator=(::Wave const &wave) {
                this->frameCount = wave.frameCount;
                this->sampleRate = wave.sampleRate;
                this->sampleSize = wave.sampleSize;
                this->channels = wave.channels;
                this->data = wave.data;
            }

        //* Custom ---------------------------------------------------------- //

            ~Wave() {
                if (_isLoaded) {
                    this->unload();
                }
            }

        //* Built-in -------------------------------------------------------- //

            // Unload  data from memory (RAM and/or VRAM)
            void unload();
            // Export  data to file, returns true on success
            bool exportToFile(std::string const &fileName) const;
            // Export  sample data to code (.h), returns true on success
            bool exportAsCode(std::string const &fileName) const;
            // Convert  data to desired format
            void format(int sampleRate, int sampleSize, int channels);
            // Crop a wave to defined samples range
            void waveCrop(int initSample, int finalSample);

            bool isLoaded() const {
                return _isLoaded;
            }

        //* Operators ------------------------------------------------------- //

            bool operator==(const Wave &wave) {
                return (this->frameCount == wave.frameCount
                    &&  this->sampleRate == wave.sampleRate
                    &&  this->sampleSize == wave.sampleSize
                    &&  this->channels   == wave.channels
                    &&  this->data       == wave.data);
            }


        private:
            bool _isLoaded;

    };
}

#endif /* !WAVE_HPP_ */
