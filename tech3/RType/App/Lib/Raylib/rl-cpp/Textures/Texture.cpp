/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** texture
*/

#include "Lib/Raylib/rl-cpp/Textures/Texture.hpp"

// TEXTUREMANAGER --------------------------------------------------------------

// template <>
// template <>
// void rl::TextureManager::insertData<rl::TextureDatas const &>(rl::TextureDatas const &data)
// {

//     if (this->_datas.find(data.first) != this->_datas.end()) {
//         throw(rl::Error("Texture \"" + std::to_string(data.first) + "\" already exists.", "TextureManager::insertData"));
//     }

//     rl::Texture texture(data.second);
//     this->_datas.insert(std::make_pair(data.first, texture));
// }

// template <>                           // alaide :) 8=>
// rl::Texture rl::TextureManager::getData(rl::TextureType const &id)
// {
//     if (this->_datas.find(id) == this->_datas.end()) {
//         throw(rl::Error("Texture \"" + std::to_string(id) + "\" doesn't exist.", "TextureManager::insertData"));
//     }
//     rl::Texture texture(this->_datas[id]);
//     return (texture);
// }

// template <>
// rl::TextureManager::~DataManager<rl::Texture, rl::TextureType>()
// {
//     for (auto pair : this->_datas) {
//         pair.second.unload();
//     }
// }

// TEXTURE ---------------------------------------------------------------------

// rl::Texture::Texture(rl::TextureType const &id) : ::Texture{TextureManager::getInstance().getData(id)}, _isLoaded(true) {};


void rl::Texture::unload()
{
    // if (this->_isLoaded) {
    ::UnloadTexture(*this);
    //     this->_isLoaded = false;
    // }
}

void rl::Texture::update(const void *pixels) const
{
    if (!_isLoaded)
        throw rl::Error("Texture::update: Texture is not loaded", "Texture::update");
    UpdateTexture(*this, pixels);
}

void rl::Texture::updateRec(rl::Rectangle const &rec, const void *pixels) const
{
    if (!_isLoaded)
        throw rl::Error("Texture::updateRec: Texture is not loaded", "Texture::updateRec");
    UpdateTextureRec(*this, rec, pixels);
}

void rl::Texture::drawAnim() const
{
    if (!_isLoaded)
        throw rl::Error("Texture::drawVect: Texture is not loaded", "Texture::drawVect");
    
    rl::Rectangle rec(this->animRect.x * this->scale.x, this->animRect.y * this->scale.y, this->animRect.w * this->scale.x, this->animRect.h * this->scale.y);
    DrawTextureRec(*this, rec, this->position, this->tint);
}

void rl::Texture::draw() const
{
    if (!_isLoaded)
        throw rl::Error("Texture::drawVect: Texture is not loaded", "Texture::drawVect");

    DrawTextureV(*this, this->position, this->tint);
}

void rl::Texture::drawEx(rl::Vector2 const &position, float rotation, float scale, rl::Color const &tint) const
{
    if (!_isLoaded)
        throw rl::Error("Texture::drawEx: Texture is not loaded", "Texture::drawEx");
    DrawTextureEx(*this, position, rotation, scale, tint);
}

void rl::Texture::drawRec(rl::Rectangle const &source, rl::Vector2 const &position, rl::Color const &tint) const
{
    if (!_isLoaded)
        throw rl::Error("Texture::drawRec: Texture is not loaded", "Texture::drawRec");
    DrawTextureRec(*this, source, position, tint);
}
