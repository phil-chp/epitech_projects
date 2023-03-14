/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Music
*/

#include "Music.hpp"

// ISOUND ------------------------------------------------------------------- //

void rl::Music::play() const
{
    if (!_isLoaded)
        throw rl::Error("Music::play: Music is not loaded", "Music::play");
    ::PlayMusicStream(*this);
}

void rl::Music::unload()
{
    if (_isLoaded) {
        ::UnloadMusicStream(*this);
        _isLoaded = false;
    }
}

void rl::Music::update(const void *data, int frameCount) const
{
    (void)data;
    (void)frameCount;
    if (!_isLoaded)
        throw rl::Error("Music::update: Music is not loaded", "Music::update");
    ::UpdateMusicStream(*this);
}

void rl::Music::stop() const
{
    if (!_isLoaded)
        throw rl::Error("Music::stop: Music is not loaded", "Music::stop");
    if (this->isPlaying())
        ::StopMusicStream(*this);
}

void rl::Music::pause() const
{
    if (!_isLoaded)
        throw rl::Error("Music::pause: Music is not loaded", "Music::pause");
    if (this->isPlaying())
        ::PauseMusicStream(*this);
}

void rl::Music::resume() const
{
    if (!_isLoaded)
        throw rl::Error("Music::resume: Music is not loaded", "Music::resume");
    ::ResumeMusicStream(*this);
}

bool rl::Music::isPlaying() const
{
    if (!_isLoaded)
        throw rl::Error("Music::isPlaying: Music is not loaded", "Music::isPlaying");
    return ::IsMusicStreamPlaying(*this);
}

// VOLUME ------------------------------------------------------------------- //

void rl::Music::updateVolume() const
{
    if (!_isLoaded)
        throw rl::Error("Music::updateVolume: Music is not loaded", "Music::updateVolume");
    ::SetMusicVolume(*this, this->getVolume());
}

// MUSIC -------------------------------------------------------------------- //

void rl::Music::loadNew(rl::Music const &music)
{
    float volume = this->getVolume();

    if (_isLoaded) {
        this->stop();
        this->unload();
    }
    *this = music;
    this->setVolume(volume);
    _isLoaded = true;
}

void rl::Music::seek(float position) const
{
    if (!_isLoaded)
        throw rl::Error("Music::seek: Music is not loaded", "Music::seek");
    ::SeekMusicStream(*this, position);
}

float rl::Music::getLength() const
{
    if (!_isLoaded)
        throw rl::Error("Music::getLength: Music is not loaded", "Music::getLength");
    return (::GetMusicTimeLength(*this));
}

float rl::Music::getPosition() const
{
    if (!_isLoaded)
        throw rl::Error("Music::getPosition: Music is not loaded", "Music::getPosition");
    return (::GetMusicTimePlayed(*this));
}
