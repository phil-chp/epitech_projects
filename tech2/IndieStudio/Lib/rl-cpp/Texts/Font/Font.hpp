/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Font
*/

#ifndef FONT_HPP_
    #define FONT_HPP_

    #include "Raylib-cpp.hpp"
    #include "Colors/Colors.hpp"
    #include "Error/Error.hpp"
    #include <iostream>
    #include <vector>

namespace rl {
    class Font : public ::Font {
        public:
            Font(std::string const &fileName = "Assets/fonts/Oretans-Shadow.ttf") : ::Font{::LoadFont(fileName.c_str())}, _isLoaded(true) {}
            explicit Font(std::string const &fileName, int fontSize, std::vector<int> &fontChars, int glyphCount)
                : ::Font{::LoadFontEx(fileName.c_str(), fontSize, fontChars.data(), glyphCount)}, _isLoaded(true) {}
            Font(Image const &image, Color const &key, int firstChar) : ::Font{::LoadFontFromImage(image, key, firstChar)}, _isLoaded(true) {}
            explicit Font(std::string const &fileType,
                          std::vector<unsigned char> const &fileData,
                          int dataSize,
                          int fontSize,
                          std::vector<int> &fontChars,
                          int glyphCount)
                : ::Font{::LoadFontFromMemory(fileType.c_str(), fileData.data(), dataSize, fontSize, fontChars.data(), glyphCount)}, _isLoaded(true) {}

            void operator=(const ::Font& font) {
                this->baseSize = font.baseSize;
                this->glyphCount = font.glyphCount;
                this->glyphCount = font.glyphCount;
                this->glyphPadding = font.glyphPadding;
                this->texture = font.texture;
                this->recs = font.recs;
                this->glyphs = font.glyphs;
            }

        //* Custom ---------------------------------------------------------- //

            ~Font() {
                if (_isLoaded) {
                    this->unload();
                }
            }

        //* Built-in -------------------------------------------------------- //

            // Unload Font from GPU memory (VRAM)
            void unload() {
                if (this->_isLoaded) {
                    ::UnloadFont(*this);
                    _isLoaded = false;
                }
            }

            bool isLoaded() const {
                return _isLoaded;
            }

        private:
            bool _isLoaded;
    };
}

#endif /* !FONT_HPP_ */
