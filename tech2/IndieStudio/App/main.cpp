/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "ECS/Coordinator.hpp"
#include "Utils/GameManager.hpp"
// #include "animations.hpp"
#include "Raylib.hpp"
#include <chrono>

#include <cstdlib>
#include <ctime>

static void init_texture()
{
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(rl::DEFAULT_TEXTURE);
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_BUTTON,        "Assets/textures/button.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_CRATE,         "Assets/models/crate/crate.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_CRATE_NORMAL,  "Assets/models/crate/crate_normal.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PILLAR,        "Assets/models/pillar/pillar.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PILLAR_NORMAL, "Assets/models/pillar/pillar_normal.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_BOMB,          "Assets/models/bomb/bomb.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_BOMB_SPEC,     "Assets/models/bomb/bomb_spec.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_BOMB_NORMAL,   "Assets/models/bomb/bomb_normal.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_GROUND,        "Assets/textures/floor.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PLAYER_WHITE,  "Assets/models/player/player_white.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PLAYER_BLACK,  "Assets/models/player/player_black.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PLAYER_RED,    "Assets/models/player/player_red.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PLAYER_GREEN,  "Assets/models/player/player_green.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PLAYER_BLUE,   "Assets/models/player/player_blue.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_PLAYER_YELLOW, "Assets/models/player/player_yellow.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_NEBULA,        "Assets/textures/parallax/nebula_blue.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_BIG_STARS,     "Assets/textures/parallax/stars_big.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_SMALL_STARS,   "Assets/textures/parallax/stars_small.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_TITLE,         "Assets/textures/title.png"));

    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_BOMB_UP,    "Assets/models/items/item_bomb_up.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_BOMB_DOWN,  "Assets/models/items/item_bomb_down.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_FIRE_UP,    "Assets/models/items/item_fire_up.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_FIRE_DOWN,  "Assets/models/items/item_fire_down.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_SPEED_UP,   "Assets/models/items/item_fire_up.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_SPEED_DOWN, "Assets/models/items/item_fire_down.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_FIRE_MAX,   "Assets/models/items/item_fire_max.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_BLUE_GLOVE, "Assets/models/items/item_blue_glove.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_BOX_GLOVE,  "Assets/models/items/item_box_glove.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_FIRE_PASS,  "Assets/models/items/item_fire_pass.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_HEART,      "Assets/models/items/item_heart.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_KICK_BOMBS, "Assets/models/items/item_kick_bombs.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_PASS_BOMB,  "Assets/models/items/item_pass_bomb.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_PASS_CRATE, "Assets/models/items/item_pass_crate.png"));
    rl::TextureManager::getInstance().insertData<rl::TextureDatas const &>(std::make_pair(rl::TextureType::TEXTURE_ITEM_SKULL,      "Assets/models/items/item_skull.png"));
}

static void init_model()
{
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::DEFAULT_MODEL);
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PLAYER_WHITE,
        .modelPath = "Assets/models/player/player.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PLAYER_WHITE)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PLAYER_BLACK,
        .modelPath = "Assets/models/player/player.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PLAYER_BLACK)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PLAYER_BLUE,
        .modelPath = "Assets/models/player/player.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PLAYER_BLUE)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PLAYER_RED,
        .modelPath = "Assets/models/player/player.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PLAYER_RED)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PLAYER_GREEN,
        .modelPath = "Assets/models/player/player.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PLAYER_GREEN)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PLAYER_YELLOW,
        .modelPath = "Assets/models/player/player.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PLAYER_YELLOW)
        }
    });

    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_CRATE,
        .modelPath = "Assets/models/crate/missing_model.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE,   rl::TEXTURE_CRATE),
            std::make_pair(rl::MAT_NORMAL,    rl::TEXTURE_CRATE_NORMAL)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_PILLAR,
        .modelPath = "Assets/models/pillar/pillar.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE, rl::TEXTURE_PILLAR),
            std::make_pair(rl::MAT_NORMAL,  rl::TEXTURE_PILLAR_NORMAL)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_BOMB,
        .modelPath = "Assets/models/bomb/bomb.iqm",
        .materialTextureMap = {
            std::make_pair(rl::MAT_DIFFUSE,  rl::TEXTURE_BOMB),
            std::make_pair(rl::MAT_NORMAL,   rl::TEXTURE_BOMB_NORMAL),
            std::make_pair(rl::MAT_SPECULAR, rl::TEXTURE_BOMB_SPEC)
        }
    });
    rl::ModelManager::getInstance().insertData<rl::ModelDatas const &>(rl::ModelDatas {
        .id = rl::ModelType::MODEL_ITEM,
        .modelPath = "Assets/models/items/item.iqm",
        .materialTextureMap = {}
    });
}

static void init_animation()
{
    rl::ModelAnimationManager::getInstance().insertData<rl::ModelAnimationDatas const &>(rl::DEFAULT_MODEL_ANIM);
    rl::ModelAnimationManager::getInstance().insertData<rl::ModelAnimationDatas const &>(rl::ModelAnimationDatas {
        .id = rl::ModelAnimationType::ANIM_PLAYER,
        .modelPath = "Assets/models/player/player.iqm",
        .count = 2,
    });
    rl::ModelAnimationManager::getInstance().insertData<rl::ModelAnimationDatas const &>(rl::ModelAnimationDatas {
        .id = rl::ModelAnimationType::ANIM_BOMB,
        .modelPath = "Assets/models/bomb/bomb.iqm",
        .count = 0,
    });
}

static void init_sound()
{
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::DEFAULT_SOUND);
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BATTLE_COUNTDOWN, "Assets/sounds/battle/battle_countdown.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BATTLE_END, "Assets/sounds/battle/battle_end.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BATTLE_START, "Assets/sounds/battle/battle_start.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BOMB_EXPLODE, "Assets/sounds/bomb/bomb_explode.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BOMB_FUSE, "Assets/sounds/bomb/bomb_fuse.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BOMB_PLACE, "Assets/sounds/bomb/bomb_place.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_CRATE_BURN, "Assets/sounds/crate/crate_burn.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_CRATE_DROP, "Assets/sounds/crate/crate_drop.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BONUS_PICKUP, "Assets/sounds/misc/bonus_pickup.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_BUTTON_PRESS, "Assets/sounds/misc/button_press.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_GAME_START, "Assets/sounds/misc/game_start.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_PLAYER_DEATH, "Assets/sounds/player/player_death.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_PLAYER_SELECT_JOIN, "Assets/sounds/player/player_select_join.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_PLAYER_SELECT_READY, "Assets/sounds/player/player_select_ready.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::SOUND_PLAYER_STEP, "Assets/sounds/player/player_step.wav" });
    rl::SoundManager::getInstance().insertData<rl::SoundDatas const &>(rl::SoundDatas { rl::SoundType::BACKGROUND_MUSIC, "Assets/sounds/misc/menu.ogg" });
}

static void bomberman()
{
    float dt = 0.0;

    while (!rl::Window::getInstance().shouldClose() && !rl::Window::getInstance().shouldExit()) {
        if (!rl::Window::getInstance().isSoundPlaying(rl::SoundManager::getInstance().getData(rl::BACKGROUND_MUSIC))) {
            rl::SoundManager::getInstance().getData(rl::BACKGROUND_MUSIC).play();
        }
        auto startTime = std::chrono::high_resolution_clock::now();
        GameManager::getInstance().loopWindow(dt);

        if (rl::Keyboard::isKeyPressed(rl::KEY_F11) || rl::Keyboard::isKeyPressed(rl::KEY_F4))
            rl::Window::getInstance().toggleFullscreen();

        if (GameManager::getInstance().isSwitching()) GameManager::getInstance().switchWindow();
        auto stopTime = std::chrono::high_resolution_clock::now();
        dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
}

int main(void)
{
    std::srand(std::time(nullptr));
    SetTraceLogLevel(LOG_ERROR);
    rl::Window::getInstance();

    rl::ShaderManager::getInstance().insertData<rl::ShaderDatas const &>(rl::EXPLOSION_SHADER_DATAS);
    init_texture();
    init_model();
    init_animation();
    init_sound();

    GameManager::getInstance();

    bomberman();

    rl::Window::getInstance().close();
    return 0;
}
