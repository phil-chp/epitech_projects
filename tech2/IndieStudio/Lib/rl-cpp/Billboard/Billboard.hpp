/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo [WSL : Ubuntu]
** File description:
** Billboard
*/

#ifndef BILLBOARD_HPP_
#define BILLBOARD_HPP_

    #include "Raylib-cpp.hpp"
    #include "Windows/Windows.hpp"
    #include "Vectors/Vectors.hpp"
    #include "Colors/Colors.hpp"
    #include "Textures/Textures.hpp"
    #include "Drawable/IDrawable.hpp"

    #include <string>

namespace rl {

    class Billboard : public IDrawable {
        public:
            Billboard();
            Billboard(Texture texture, Vector3 position, float size, Color tint = RL_WHITE) : _texture{texture}, _position{position}, _size{size}, _tint{tint} {};
            // Billboard(Texture texture, Rectangle source, Vector3 position, Vector2 size, Color tint = RL_WHITE);
            // Billboard(Texture texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint = RL_WHITE);

            ~Billboard() = default;

            void draw(Camera const &camera) const; // TODO: override

            // TODO: implement DrawBillboardRec and DrawBillboardPro

            //* Getters -------------------------------------------------------- //
            Texture getTexture() const {
                return this->_texture;
            }
            Vector3 getPosition() const {
                return this->_position;
            }
            float getSize() const {
                return this->_size;
            }
            Color getTint() const {
                return this->_tint;
            }

            //* Setters -------------------------------------------------------- //
            void setTexture(Texture const &texture) {
                this->_texture = texture;
            }
            void setPosition(Vector3 const &position) {
                this->_position = position;
            }
            void setSize(float size) {
                this->_size = size;
            }
            void setTint(Color const &tint) {
                this->_tint = tint;
            }


        private:
            Texture _texture;
            Vector3 _position;
            float _size;
            Color _tint;
    };
}

#endif /* !BILLBOARD_HPP_ */