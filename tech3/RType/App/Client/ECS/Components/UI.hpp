/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** UI struct
*/

#ifndef UI_HPP_
    #define UI_HPP_

    #include "Utils/Vector2.hpp"
    #include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"

namespace ecs {
    struct UI {
        short int maxPlayer;
        // short int connectedPlayer;
        // short int deadPlayer
        short int mainPlayer;
        std::vector<::game::Vector2> playerPos;
        std::vector<int> score;
        std::vector<short int> life;
        int weaponId;
        short int charge;
         int heartAnimFrame;
         float heartAnimDelay;
         float heartAnimActualDelay;
        ::game::Vector2 iconOffset;
        ::game::Vector2 nameOffset;
        ::game::Vector2 scoreOffset;
        ::game::Vector2 lifeOffset;
        ::game::Vector2 weapOffset;
        // ::game::Vector2 chargePos;
        // std::vector<::rl::Text> scoreText;
        // std::vector<::rl::Text> lifeText;
        // std::vector<::rl::Text> upgradeText;
        // std::vector<::rl::Texture> heart;
        // std::vector<::rl::Texture> icon;
        ::rl::Text txt;
        ::rl::Texture heart;
        ::rl::Texture icon;
    };
}

//  *______________|
//  |icon          |
//  |        nom   |
//  |        vie   |
//  |        tir   |
//  _______________

#endif /* !UI_HPP_ */
