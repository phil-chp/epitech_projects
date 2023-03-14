/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Image
*/

#ifndef IMAGE_HPP_
    #define IMAGE_HPP_

    #include "Raylib-cpp.hpp"
    #include "Colors/Color.hpp"
    #include "Drawable/IDrawable.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Shapes/Rectangle/Rectangle.hpp"
    #include "Error/Error.hpp"
    #include <string>

namespace rl {
    class Image : public ::Image {
        public:
            explicit Image(const std::string &filePath, Vector2 const &Pos) : ::Image{::LoadImage(filePath.c_str())}, pos(Pos), _isLoaded(true) {}
            explicit Image(::Image const &image) : ::Image{image}, pos{0, 0}, _isLoaded(true) {};

            void operator=(const ::Image &image) {
                this->data = image.data;
                this->width = image.width;
                this->height = image.height;
                this->mipmaps = image.mipmaps;
                this->format = image.format;
            }

        //* Custom ---------------------------------------------------------- //

            ~Image() {
                if (_isLoaded)
                    this->unload();
            }

        //* Built-in -------------------------------------------------------- //

            // Unload image from GPU memory (VRAM)
            void unload();
            // Convert image data to desired format
            void convertFormat(int newFormat);
            // Crop an image to a defined rectangle
            void crop(Rectangle const &crop);
            // Resize image (Bicubic scaling algorithm)
            void resize(int newWidth, int newHeight);
            // Flip image vertically
            void flipVertical();
            // Flip image horizontally
            void flipHorizontal();
            // Rotate image clockwise 90deg
            void rotateCW();
            // Rotate image counter-clockwise 90deg
            void rotateCCW();
            // Draw image
            void draw(Image *dst, Rectangle const &srcRec, Rectangle const &dstRec, Color const &tint) const;
            // Clear image background with given color
            void clearBackground(Color const &color);

            bool isLoaded() const {
                return _isLoaded;
            }

        //* Attributes ------------------------------------------------------ //
            Vector2 pos;

        private:
            bool _isLoaded;



    };
}

#endif /* !IMAGE_HPP_ */
