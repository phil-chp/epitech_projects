/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RLShader
*/

#ifndef RLSHADER_HPP_
#define RLSHADER_HPP_

    #include "ECS/Components/ShaderedDrawable.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"

namespace ecs {
    typedef ShaderedDrawable<::rl::Shader> RLShader;
};

#endif /* !RLSHADER_HPP_ */
