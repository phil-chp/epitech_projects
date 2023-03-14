/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** texture
*/

#ifndef TEXTURE_HPP_
    #define TEXTURE_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Utils/DataManager.hpp"
    #include "Utils/Rect.hpp"
    #include "Lib/Raylib/rl-cpp/Image/Image.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vector2.hpp"
    #include "Lib/Raylib/rl-cpp/Colors/Colors.hpp"
    #include "Lib/Raylib/rl-cpp/Error/Error.hpp"
    #include "Lib/Raylib/rl-cpp/Shapes/Rectangle/Rectangle.hpp"
    #include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"
    #include <string>

namespace rl {

    // enum TextureType {
    //     TEXTURE_MISSING = -1,
    //     TEXTURE_BUTTON,
    //     TEXTURE_CRATE,
    //     TEXTURE_CRATE_NORMAL,
    //     TEXTURE_CRATE_ROUGH,
    //     TEXTURE_PILLAR,
    //     TEXTURE_PILLAR_NORMAL,
    //     TEXTURE_BOMB,
    //     TEXTURE_BOMB_SPEC,
    //     TEXTURE_BOMB_NORMAL,
    //     TEXTURE_GROUND,
    //     TEXTURE_PLAYER_WHITE,
    //     TEXTURE_PLAYER_BLACK,
    //     TEXTURE_PLAYER_RED,
    //     TEXTURE_PLAYER_GREEN,
    //     TEXTURE_PLAYER_BLUE,
    //     TEXTURE_PLAYER_YELLOW,
    //     TEXTURE_NEBULA,
    //     TEXTURE_BIG_STARS,
    //     TEXTURE_SMALL_STARS,
    //     TEXTURE_TITLE,
    //     TEXTURE_ITEM_BOMB_UP,
    //     TEXTURE_ITEM_BOMB_DOWN,
    //     TEXTURE_ITEM_FIRE_UP,
    //     TEXTURE_ITEM_FIRE_DOWN,
    //     TEXTURE_ITEM_SPEED_UP,
    //     TEXTURE_ITEM_SPEED_DOWN,
    //     TEXTURE_ITEM_BLUE_GLOVE,
    //     TEXTURE_ITEM_BOX_GLOVE,
    //     TEXTURE_ITEM_FIRE_MAX,
    //     TEXTURE_ITEM_FIRE_PASS,
    //     TEXTURE_ITEM_HEART,
    //     TEXTURE_ITEM_KICK_BOMBS,
    //     TEXTURE_ITEM_PASS_BOMB,
    //     TEXTURE_ITEM_PASS_CRATE,
    //     TEXTURE_ITEM_SKULL
    // };

    // typedef std::pair<TextureType, std::string const> TextureDatas;
    // const TextureDatas DEFAULT_TEXTURE = std::make_pair(TEXTURE_MISSING, "Assets/Textures/missing_texture.png");

    class Texture : public IDrawable, public ::Texture {
        public:
            Texture(): position(0, 0), tint(255, 255, 255, 255), animRect(0, 0, 500, 500), _isLoaded(false), scale(1.0, 1.0) {};
            // explicit Texture(TextureType const &id = TEXTURE_MISSING);
            // explicit Texture(std::string const &filePath = "", Color const &color = RL_WHITE) : ::Texture{::LoadTexture(filePath.c_str())}, tint(color) ,_isLoaded(true) {}
            explicit Texture(std::string const &filePath, Color const &color = RL_WHITE) : ::Texture{::LoadTexture(filePath.c_str())}, tint(color) , _isLoaded(true) 
            {
                this->animRect = ::game::Rect(0, 0, this->width, this->height);
                // std::cout << filePath << ": \n\t rect = {" << this->animRect.x << ", "<< this->animRect.y << ", "<< this->animRect.w << ", "<< this->animRect.h << "}" << std::endl;
                this->_size = ::game::Vector2(this->width, this->height);
                this->scale = ::game::Vector2(1.0, 1.0);
            }
            explicit Texture(Image const &image) : ::Texture{::LoadTextureFromImage(image)}, tint(RL_RED), _isLoaded(true) {}
            explicit Texture(::Texture const &texture) : ::Texture{texture},  _isLoaded(true) {};
            // explicit Texture(rl::Rectangle rect) : _isLoaded(false) 
            // {
            //     this->id = -1;
            //     this->width = rect.width;
            //     this->height = rect.height;
            //     this->mipmaps = texture.mipmaps;
            //     this->format = texture.format;
            //     this->_isLoaded = true;
            //     this->animRect = ::game::Rect(0, 0, this->width, this->height);
            //     this->_size = ::game::Vector2(this->width, this->height);
            //     this->tint = RL_WHITE;
            //     this->position = ::game::Vector2(0, 0);
            //     this->animRect = ::game::Rect(rect.x, rect.y, rect.width, rect.height);
            //     this->_size = ::game::Vector2(rect.width, rect.height);
            //     this->scale = ::game::Vector2(1.0, 1.0);

            // };


            void operator=(const ::Texture& texture) {
                this->id = texture.id;
                this->width = texture.width;
                this->height = texture.height;
                this->mipmaps = texture.mipmaps;
                this->format = texture.format;
                this->_isLoaded = true;
                this->animRect = ::game::Rect(0, 0, this->width, this->height);
                this->_size = ::game::Vector2(this->width, this->height);
                this->tint = RL_WHITE;
                this->position = ::game::Vector2(0, 0);
            };

        //* Custom ---------------------------------------------------------- //

            ~Texture() {
                // this->unload();
            }

            void setIsLoaded(bool isLoaded) {
                this->_isLoaded = isLoaded;
            }
            bool getIsLoaded() const {
                return this->_isLoaded;
            }
            void setSize(Vector2 const &size) {
                this->width = size.x;
                this->height = size.y;
                this->_size.x = size.x;
                this->_size.y = size.y;
            }

            void setScale(Vector2 const &scale) {

                this->scale = scale;
                this->width = this->_size.x * scale.x;
                this->height = this->_size.y * scale.y;
            }

            //getscale
            Vector2 getScale() const {
                return this->scale;
            }

            ::game::Vector2 getSize() const {
                return ::game::Vector2(this->width, this->height);
            }


            float getHeight() const {
                return this->height;
            }
            float getWidth() const {
                return this->width;
            }

            static std::string initTextureFromPath(std::string const &path) {
                char skyboxFileName[256] = { 0 };

                TextCopy(skyboxFileName, path.c_str());
                std::string str(skyboxFileName);
                return (str);
            }



        //* Built-in -------------------------------------------------------- //

            // Unload texture from GPU memory (VRAM)
            void unload();
            // Update GPU texture with new data
            void update(const void *pixels) const;
            // Update GPU texture rectangle with new data
            void updateRec(Rectangle const &rec, const void *pixels) const;
            // Draw a 2D shape with position
            void draw() const override;
            // Draw a 2D shape with position and rectangle
            void drawAnim() const;
            // Draw a 2D shape with extended parameters
            void drawEx(Vector2 const &position, float rotation, float scale, Color const &tint = RL_WHITE) const;
            // Draw a part of a texture defined by a rectangle
            void drawRec(Rectangle const &source, Vector2 const &position, Color const &tint = RL_WHITE) const;

            bool isLoaded() const {
                return _isLoaded;
            }

            Vector2 position;
            Color tint;
            ::game::Rect animRect;
            Vector2 scale;
        private:
            Vector2 _size;
            bool _isLoaded;
    };

    // typedef DataManager<rl::Texture, rl::TextureType> TextureManager;
}

#endif /* !TEXTURE_HPP_ */
