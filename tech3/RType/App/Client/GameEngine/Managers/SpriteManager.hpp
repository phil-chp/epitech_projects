/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** SpriteManager
*/

#ifndef SPRITEMANAGER_HPP_
    #define SPRITEMANAGER_HPP_

    #include "Utils/DataManager.hpp"
    #include "Lib/Raylib/rl-cpp/Textures/Texture.hpp"

namespace engine {
enum SpriteType {
    SPR_MISSING = -1,
    SPR_DEFAULT,
    SPR_GHOST,
    SPR_BUTTON ,
    BG_LAYER1,
    BG_LAYER2,
    BG_LAYER4,
    BG_LAYER3,
    BG_MENU1,
    BG_MENU2,
    BG_MENU4,
    BG_MENU3,
    READY_BUTTON,
    SPR_PLAYER,
    SPR_SHOOT1,
    SPR_RTYPE3,
    SPR_BONUS,
    SPR_ENEMY1,
    SPR_UI_HEART,
    SPR_UI_ICONS,
    SPR_WALL,
    SPR_RAYGUN,
    SPR_BONUS2,
    SPR_CYBORG_BOB,
    SPR_CYBORG_DAMS,
    SPR_CYBORG_MEGAKONG,
    SPR_ALIEN,
    SPR_BERIC,
    SPR_CONTREUNO,
    SPR_FEUR
};
typedef DataManager<::rl::Texture, SpriteType> SpriteManager;

} // namespace engine

#endif /* !SPRITEMANAGER_HPP_ */
