/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Image
*/

#include "Lib/Raylib/rl-cpp/Image/Image.hpp"

void rl::Image::unload()
{
    if (_isLoaded) {
        ::UnloadImage(*this);
        _isLoaded = false;
    }
}

void rl::Image::convertFormat(int newFormat)
{
    if (!_isLoaded)
        throw rl::Error("Image::convertFormat: Image is not loaded", "Image::convertFormat");
    ::ImageFormat(this, newFormat);
}

void rl::Image::crop(rl::Rectangle const &crop)
{
    if (!_isLoaded)
        throw rl::Error("Image::crop: Image is not loaded", "Image::crop");
    ::ImageCrop(this, crop);
}

void rl::Image::resize(int newWidth, int newHeight)
{
    if (!_isLoaded)
        throw rl::Error("Image::resize: Image is not loaded", "Image::resize");
    ::ImageResize(this, newWidth, newHeight);
}

void rl::Image::flipVertical()
{
    if (!_isLoaded)
        throw rl::Error("Image::flipVertical: Image is not loaded", "Image::flipVertical");
    ::ImageFlipVertical(this);
}

void rl::Image::flipHorizontal()
{
    if (!_isLoaded)
        throw rl::Error("Image::flipHorizontal: Image is not loaded", "Image::flipHorizontal");
    ::ImageFlipHorizontal(this);
}

void rl::Image::rotateCW()
{
    if (!_isLoaded)
        throw rl::Error("Image::rotateCW: Image is not loaded", "Image::rotateCW");
    ::ImageRotateCW(this);
}

void rl::Image::rotateCCW()
{
    if (!_isLoaded)
        throw rl::Error("Image::rotateCCW: Image is not loaded", "Image::rotateCCW");
    ::ImageRotateCCW(this);
}

void rl::Image::clearBackground(Color const &color)
{
    if (!_isLoaded)
        throw rl::Error("Image::clearBackground: Image is not loaded", "Image::clearBackground");
    ::ImageClearBackground(this, color);
}

// TODO: Override draw
void rl::Image::draw(Image *dst, Rectangle const &srcRec, Rectangle const &dstRec, Color const &tint) const
{
    if (!_isLoaded)
        throw rl::Error("Image::draw: Image is not loaded", "Image::draw");
    ::ImageDraw(dst, *this, srcRec, dstRec, tint);
}
