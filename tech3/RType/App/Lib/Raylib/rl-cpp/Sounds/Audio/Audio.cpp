/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Audio
*/

#include "Lib/Raylib/rl-cpp/Sounds/Audio/Audio.hpp"

void rl::Audio::initDevice()
{
    if (::IsAudioDeviceReady())
        throw std::runtime_error("Audio device is already initialized");
    ::InitAudioDevice();
}

void rl::Audio::close()
{
    if (!::IsAudioDeviceReady())
        throw std::runtime_error("Audio device is not initialized");
    ::CloseAudioDevice();
}

bool rl::Audio::isReady()
{
    return (::IsAudioDeviceReady());
}

void rl::Audio::setVolume(float volume)
{
    ::SetMasterVolume(volume);
}

void rl::Audio::playSoundMulti(rl::Sound const &sound)
{
    ::PlaySoundMulti(sound);
}

void rl::Audio::stopSoundMulti()
{
    ::StopSoundMulti();
}

int rl::Audio::getSoundsPlaying()
{
    return (::GetSoundsPlaying());
}

// TODO: std::copy() of a float * to a std::vector<float>
float *rl::Audio::loadWaveSamples(rl::Wave const &wave)
{
    return (::LoadWaveSamples(wave));
}

void rl::Audio::unloadWaveSamples(std::vector<float> &samples)
{
    ::UnloadWaveSamples(samples.data());
}
