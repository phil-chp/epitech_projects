/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** RenderTexture
*/

#ifndef RENDERTEXTURE_HPP_
    #define RENDERTEXTURE_HPP_

    #include "Raylib-cpp.hpp"
    #include "Image/Image.hpp"
    #include <string>

namespace rl {
    class RenderTexture : public ::RenderTexture {
        public:
            RenderTexture(int width, int height) : ::RenderTexture{::LoadRenderTexture(width, height)}, _isLoaded(true) {}
            explicit RenderTexture(::RenderTexture const &renderTexture) : ::RenderTexture{renderTexture}, _isLoaded(true) {};

            void operator=(::RenderTexture const &renderTexture) {
                this->id = renderTexture.id;
                this->texture = renderTexture.texture;
                this->depth = renderTexture.depth;
            }

        //* Custom ---------------------------------------------------------- //

            ~RenderTexture() {
                if (_isLoaded) {
                    this->unload();
                }
            };

        //* Built-in -------------------------------------------------------- //

            void unload() {
                if (_isLoaded) {
                    ::UnloadRenderTexture(*this);
                    _isLoaded = false;
                }
            };

            bool isLoaded() const {
                return _isLoaded;
            };

        private:
            bool _isLoaded;

    };
}

#endif /* !RENDERTEXTURE_HPP_ */
