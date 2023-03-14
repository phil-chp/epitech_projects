/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** AudioStream
*/

#include "Lib/Raylib/rl-cpp/Sounds/AudioStream/AudioStream.hpp"

// ISOUND ------------------------------------------------------------------- //

void rl::AudioStream::play() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::play: AudioStream is not loaded", "AudioStream::play");
    ::PlayAudioStream(*this);
}

void rl::AudioStream::unload()
{
    if (_isLoaded) {
        ::UnloadAudioStream(*this);
        _isLoaded = false;
    }
}

void rl::AudioStream::update(void const *data, int frameCount) const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::update: AudioStream is not loaded", "AudioStream::update");
    ::UpdateAudioStream(*this, data, frameCount);
}

void rl::AudioStream::stop() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::stop: AudioStream is not loaded", "AudioStream::stop");
    if (this->isPlaying())
        ::StopAudioStream(*this);
}

void rl::AudioStream::pause() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::pause: AudioStream is not loaded", "AudioStream::pause");

    if (this->isPlaying())
        ::PauseAudioStream(*this);
}

void rl::AudioStream::resume() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::resume: AudioStream is not loaded", "AudioStream::resume");
    ::ResumeAudioStream(*this);
}

bool rl::AudioStream::isPlaying() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::isPlaying: AudioStream is not loaded", "AudioStream::isPlaying");
    return ::IsAudioStreamPlaying(*this);
}

// VOLUME ------------------------------------------------------------------- //

void rl::AudioStream::updateVolume() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::updateVolume: AudioStream is not loaded", "AudioStream::updateVolume");
    ::SetAudioStreamVolume(*this, this->getVolume());
}

// AUDIOSTREAM -------------------------------------------------------------- //

void rl::AudioStream::loadNew(rl::AudioStream const &audioStream)
{
    float volume = this->getVolume();

    if (_isLoaded) {
        this->stop();
        this->unload();
    }
    *this = audioStream;
    this->setVolume(volume);
    _isLoaded = true;
}

bool rl::AudioStream::isProcessed() const
{
    if (!_isLoaded)
        throw rl::Error("AudioStream::isProcessed: AudioStream is not loaded", "AudioStream::isProcessed");
    return (::IsAudioStreamProcessed(*this));
}
