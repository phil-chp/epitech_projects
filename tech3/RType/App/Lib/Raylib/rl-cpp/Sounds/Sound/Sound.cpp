/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Sound
*/

#include "Lib/Raylib/rl-cpp/Sounds/Sound/Sound.hpp"

// SOUND MANAGER ------------------------------------------------------------ //

// template <>
// template <>
// void rl::SoundManager::insertData<rl::SoundDatas const&>(rl::SoundDatas const &data)
// {

//     if (this->_datas.find(data.id) != this->_datas.end()) {
//         throw(rl::Error("Model \"" + std::to_string(data.id) + "\" already exists.", "ModelManager::insertData"));
//     }

//     rl::Sound sound(data.soundPath);
//     this->_datas.insert(std::make_pair(data.id, sound));
// }

// template <>
// rl::Sound rl::SoundManager::getData(rl::SoundType const &id)
// {
//     if (this->_datas.find(id) == this->_datas.end()) {
//         throw(rl::Error("Model \"" + std::to_string(id) + "\" doesn't exist.", "ModelManager::getData"));
//     }
//     rl::Sound sound(this->_datas[id]);
//     return (sound);
// }


// SOUND -------------------------------------------------------------------- //

rl::Sound::Sound(rl::SoundType const &type)
    : ::Sound{}
    , _isLoaded(true)
{
    this->play();
}

// ISOUND ------------------------------------------------------------------- //

void rl::Sound::play() const
{
    if (!_isLoaded)
        throw rl::Error("Sound::play: Sound is not loaded", "Sound::play");
    ::PlaySound(*this);
}

void rl::Sound::unload()
{
    if (_isLoaded) {
        ::UnloadSound(*this);
        _isLoaded = false;
    }
}

void rl::Sound::update(void const *data, int frameCount) const
{
    if (!_isLoaded)
        throw rl::Error("Sound::update: Sound is not loaded", "Sound::update");
    ::UpdateSound(*this, data, frameCount);
}

void rl::Sound::stop() const
{
    if (!_isLoaded)
        throw rl::Error("Sound::stop: Sound is not loaded", "Sound::stop");
    if (this->isPlaying())
        ::StopSound(*this);
}

void rl::Sound::pause() const
{
    if (!_isLoaded)
        throw rl::Error("Sound::pause: Sound is not loaded", "Sound::pause");
    if (this->isPlaying())
        ::PauseSound(*this);
}

void rl::Sound::resume() const
{
    if (!_isLoaded)
        throw rl::Error("Sound::resume: Sound is not loaded", "Sound::resume");
    ::ResumeSound(*this);
}

bool rl::Sound::isPlaying() const
{
    if (!_isLoaded)
        throw rl::Error("Sound::isPlaying: Sound is not loaded", "Sound::isPlaying");
    return ::IsSoundPlaying(*this);
}

// VOLUME ------------------------------------------------------------------- //

void rl::Sound::updateVolume() const
{
    if (!_isLoaded)
        throw rl::Error("Sound::updateVolume: Sound is not loaded", "Sound::updateVolume");
    ::SetSoundVolume(*this, this->getVolume());
}

// SOUND -------------------------------------------------------------------- //

void rl::Sound::loadNew(Sound const &sound)
{
    float volume = this->getVolume();

    if (_isLoaded) {
        this->stop();
        this->unload();
    }
    *this = sound;
    this->setVolume(volume);
    _isLoaded = true;
}
