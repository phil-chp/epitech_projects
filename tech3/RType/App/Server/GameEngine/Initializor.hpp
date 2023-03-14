/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Initializor
*/

#ifndef INITIALIZOR_HPP_
    #define INITIALIZOR_HPP_

    #include "GameEngine/Managers/SoundManager.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/Managers/FontManager.hpp"
    #include "GameEngine/Managers/ShaderManager.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
    #include "Utils/PathBuilder.hpp"


namespace engine {
using WINDOW = ::rl::Window;
using SPRITE = ::rl::Texture;
using FONT = ::rl::Font;
using SOUND = ::rl::Sound;
using SHADER = ::rl::Shader;

class Initializor {
    public:
        Initializor() = delete;
        ~Initializor() = delete;

        static void init();
        static void destroyer();

    private:
        static void initSprites();
        static void initSounds();
        static void initFonts();
        static void initShaders();

        // Sprite &getSprite() const;
        // Sound *getSound() const;

        // SpriteManager _spriteManager;
        // SoundManager _soundManager;
};
} // namespace engine

#endif /* !INITIALIZOR_HPP_ */
