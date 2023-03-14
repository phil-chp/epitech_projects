/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RLText
*/

#ifndef RLTEXT_HPP_
    #define RLTEXT_HPP_

    #include "ECS/Components/Text.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


namespace ecs {
    typedef Text<::rl::Text, ::game::Vector2> RLText;
};

#endif /* !RLTEXT_HPP_ */
