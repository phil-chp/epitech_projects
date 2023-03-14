/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Initializor
*/

#include "GameEngine/Initializor.hpp"
#include "ECS/Coordinator.hpp"
#include "ECS/Components/RLShader.hpp"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            "330"
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            "100"
#endif

void engine::Initializor::init()
{
    initSprites();
    initSounds();
    initFonts();
    initShaders();
    // initAnimation();
    // initConnexions(); maybe
}

void engine::Initializor::destroyer()
{

    ::ecs::Coordinator::getInstance().clearEntities();
    engine::FontManager::getInstance().unload();
    // engine::Manager::getInstance().unload();
    engine::SpriteManager::getInstance().unload();
    engine::ShaderManager::getInstance().unload();


    // destroyAnimation();
    // destroyConnexions(); maybe
}

void engine::Initializor::initSprites()
{
    engine::SpriteManager &sm = engine::SpriteManager::getInstance();
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Textures/missing_texture.bmp", WINDOW::getInstance().getRenderer()), SpriteType::SPR_MISSING);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Textures/r-typesheet42.bmp", WINDOW::getInstance().getRenderer()), SpriteType::SPR_GHOST);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Textures/button.bmp", WINDOW::getInstance().getRenderer()), SpriteType::SPR_BUTTON);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_PurpleBackground_Version1_Layer1.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_LAYER1);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_PurpleBackground_Version1_Layer2.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_LAYER2);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_PurpleBackground_Version1_Layer3.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_LAYER3);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_PurpleBackground_Version1_Layer4.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_LAYER4);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_RedBackground_Version1_Layer1.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_MENU1);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_RedBackground_Version1_Layer2.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_MENU2);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_RedBackground_Version1_Layer3.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_MENU3);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Parallax/bmp/T_RedBackground_Version1_Layer4.bmp", WINDOW::getInstance().getRenderer()), SpriteType::BG_MENU4);
    // engine::SpriteManager::getInstance().insertData(SPRITE("Assets/Textures/button-ready.bmp", WINDOW::getInstance().getRenderer()), SpriteType::READY_BUTTON);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures", "missing_texture.png"})), SpriteType::SPR_MISSING);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures", "r-typesheet42.png"})), SpriteType::SPR_GHOST);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures", "button.png"})), SpriteType::SPR_BUTTON);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Purple", "T_PurpleBackground_Version1_Layer1.png"})), SpriteType::BG_LAYER1);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Purple", "T_PurpleBackground_Version1_Layer2.png"})), SpriteType::BG_LAYER2);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Purple", "T_PurpleBackground_Version1_Layer3.png"})), SpriteType::BG_LAYER3);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Purple", "T_PurpleBackground_Version1_Layer4.png"})), SpriteType::BG_LAYER4);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Red", "T_RedBackground_Version1_Layer1.png"})), SpriteType::BG_MENU1);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Red", "T_RedBackground_Version1_Layer2.png"})), SpriteType::BG_MENU2);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Red", "T_RedBackground_Version1_Layer3.png"})), SpriteType::BG_MENU3);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Parallax", "png", "Red", "T_RedBackground_Version1_Layer4.png"})), SpriteType::BG_MENU4);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures", "button-ready.png"})), SpriteType::READY_BUTTON);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet1.png"})), SpriteType::SPR_SHOOT1);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet2.png"})), SpriteType::SPR_BONUS);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet42.png"})), SpriteType::SPR_PLAYER);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet5.png"})), SpriteType::SPR_ENEMY1);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Textures", "ui_heart.png"})), SpriteType::SPR_UI_HEART);
    sm.insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Textures", "real_iconv2_blaze.png"})), SpriteType::SPR_UI_ICONS);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet3.png"})), SpriteType::SPR_RTYPE3);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "wall.png"})), SpriteType::SPR_WALL);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "ray.png"})), SpriteType::SPR_RAYGUN);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "icon_bonus.png"})), SpriteType::SPR_BONUS2);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet7.png"})), SpriteType::SPR_CYBORG_BOB);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet11.png"})), SpriteType::SPR_CYBORG_DAMS);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet14.png"})), SpriteType::SPR_CYBORG_MEGAKONG);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet18.png"})), SpriteType::SPR_ALIEN);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet28.png"})), SpriteType::SPR_BERIC);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet37.png"})), SpriteType::SPR_CONTREUNO);
    sm.getInstance().insertData(SPRITE(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Textures" , "r-typesheet30.png"})), SpriteType::SPR_FEUR);
}

void engine::Initializor::initSounds()
{
    engine::SoundManager &sm = engine::SoundManager::getInstance();
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "ig.ogg"})), SoundType::SO_BG_MUS);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "bossBattle.ogg"})), SoundType::SO_BOSS1);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "Menu.ogg"})), SoundType::SO_BG_MENU);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "RayGunSoundEffect.ogg"})), SoundType::SO_RAY_GUN);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "BasicShot.ogg"})), SoundType::SO_BASIC_SHOT);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "DeathSoundEffect.ogg"})), SoundType::SO_DEATH_SE);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "LoseScreen.ogg"})), SoundType::SO_LOSE_SCREEN);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "PickUpSoundEffect.ogg"})), SoundType::SO_PICK_UP_SE);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "ShieldSoundEffect.ogg"})), SoundType::SO_SHIELD_SE);
    sm.insertData(SOUND(game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Sounds", "WinScreen.ogg"})), SoundType::SO_WIN_SCREEN);
}

void engine::Initializor::initFonts()
{
    engine::FontManager &fm = engine::FontManager::getInstance();
    // std::cout << "font" << std::endl;
    // if (TTF_Init() == -1)
    // {
    //     std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
    //     throw std::runtime_error("TTF_Init error");
    // }
    // engine::FontManager::getInstance().insertData(FONT("Assets/Fonts/Digital-Serial-Bold.ttf", 48), FontType::FONT_MISSING);
    // engine::FontManager::getInstance().insertData(FONT("Assets/Fonts/Digital-Serial-Regular.ttf", 48), FontType::FONT_DEFAULT);
    // engine::FontManager::getInstance().insertData(FONT("Assets/Fonts/Digital-Serial-Bold.ttf", 48), FontType::FONT_BOLD);
    fm.insertData(FONT(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Fonts", "Digital-Serial-Bold.ttf"})), FontType::FONT_MISSING);
    // std::cout << "font2" << std::endl;

    fm.insertData(FONT(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Fonts", "Digital-Serial-Regular.ttf"})), FontType::FONT_DEFAULT);
    fm.insertData(FONT(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Fonts", "Digital-Serial-Bold.ttf"})), FontType::FONT_BOLD);
    fm.insertData(FONT(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Fonts", "spacerangersemital.ttf"})), FontType::FONT_UI);
}

void engine::Initializor::initShaders()
{
    // engine::ShaderManager::getInstance().insertData(SHADER(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", "base_lighting_instanced.vs"}), game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", "lighting.fs"})), ShaderType::SHADER_MISSING);
    // engine::ShaderManager::getInstance().insertData(SHADER(game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", "base_lighting_instanced.vs"}), game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", "lighting.fs"})), ShaderType::SHADER_PARTICLES);
    engine::ShaderManager::getInstance().insertData(SHADER(
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "base.vs"}),
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "wave.fs"})),
        ShaderType::SHADER_WAVE
    );
    engine::ShaderManager::getInstance().insertData(SHADER(
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "base.vs"}),
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "spotlight.fs"})),
        ShaderType::SHADER_SPOTLIGHT
    );
    engine::ShaderManager::getInstance().insertData(SHADER(
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "base.vs"}),
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "reload.fs"})),
        ShaderType::SHADER_COLOR
    );
    engine::ShaderManager::getInstance().insertData(SHADER(
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "base.vs"}),
        game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "rain.fs"})),
        ShaderType::SHADER_RAIN
    );



    // engine::ShaderManager::getInstance().insertData(SHADER(
    //     game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "base.vs"}),
    //     game::PathBuilder::getPath(std::vector<std::string> {"Assets", "Shaders", std::string("glsl") + std::string(GLSL_VERSION), "galaxy.fs"})),
    //     ShaderType::SHADER_GALAXY
    // );

}
