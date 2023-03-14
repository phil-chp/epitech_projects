/*
** EPITECH PROJECT, 2022
** RType
** File description:
** FontManager
*/

#ifndef FONTMANAGER_HPP_
    #define FONTMANAGER_HPP_
    #include "Utils/DataManager.hpp"
    #include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"

namespace engine {
enum FontType {
    FONT_MISSING = -1,
    FONT_DEFAULT = 0,
    FONT_BOLD = 1,
    FONT_UI = 2
};
typedef DataManager<::rl::Font, FontType> FontManager;
};

#endif /* !FONTMANAGER_HPP_ */
