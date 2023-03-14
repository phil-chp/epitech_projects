/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Wave
*/

#include "Lib/Raylib/rl-cpp/Sounds/Wave/Wave.hpp"

void rl::Wave::unload()
{
    if (_isLoaded) {
        ::UnloadWave(*this);
        _isLoaded = false;
    }
}

bool rl::Wave::exportToFile(std::string const &fileName) const
{
    if (!_isLoaded)
        throw rl::Error("Wave::exportToFile: Wave is not loaded", "Wave::exportToFile");
    return (::ExportWave(*this, fileName.c_str()));
}

bool rl::Wave::exportAsCode(std::string const &fileName) const
{
    if (!_isLoaded)
        throw rl::Error("Wave::exportAsCode: Wave is not loaded", "Wave::exportAsCode");
    return (::ExportWaveAsCode(*this, fileName.c_str()));
}

void rl::Wave::format(int sampleRate, int sampleSize, int channels)
{
    if (!_isLoaded)
        throw rl::Error("Wave::format: Wave is not loaded", "Wave::format");
    ::WaveFormat(this, sampleRate, sampleSize, channels);
}

void rl::Wave::waveCrop(int initSample, int finalSample)
{
    if (!_isLoaded)
        throw rl::Error("Wave::waveCrop: Wave is not loaded", "Wave::waveCrop");
    ::WaveCrop(this, initSample, finalSample);
}
