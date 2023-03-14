/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Shader
*/

#include "Lib/Raylib/rl-cpp/Shaders/Shader.hpp"
// #define RLIGHTS_IMPLEMENTATION
// #include "Lib/Raylib/rl-cpp/Shaders/Rlights.h"


// template <>
// template <>
// void rl::ShaderManager::insertData<rl::ShaderDatas const &>(rl::ShaderDatas const &strings)
// {

//     if (this->_datas.find(strings[2]) != this->_datas.end()) {
//         throw(rl::Error("Shader \"" + strings[2] + "\" already exists.", "ShaderManager::insertData"));
//     }
//     rl::Shader shader(strings[0], strings[1]);

//     shader.locs[SHADER_LOC_MATRIX_MVP] = shader.getLocation("mvp");
//     shader.locs[SHADER_LOC_VECTOR_VIEW] = shader.getLocation("viewPos");
//     shader.locs[SHADER_LOC_MATRIX_MODEL] = shader.getLocationAttrib("instanceTransform");

//     int ambientLoc = shader.getLocation("ambient");
//     float array[4] = { 0.2f, 0.2f, 0.2f, 1.0f};
//     shader.setValue(ambientLoc, array, SHADER_UNIFORM_VEC4);

//     // CreateLight(LIGHT_DIRECTIONAL, rl::Vector3(50.0f, 50.0f, 0.0f), rl::Vector3(0.0), rl::RL_WHITE, shader);

//     this->_datas.insert(std::make_pair(strings[2], shader));
// }

// template <>
// rl::Shader rl::ShaderManager::getData(std::string const &name)
// {

//     if (this->_datas.find(name) == this->_datas.end()) {
//         throw(rl::Error("Shader \"" + name + "\" doesn't exist.", "ShaderManager::insertData"));
//     }
//     rl::Shader shader(this->_datas[name]);
//     return (shader);
// }

// template <>
// rl::ShaderManager::~DataManager<rl::Shader, std::string>()
// {
//     for (auto pair : this->_datas) {
//         pair.second.unload();
//     }
// }

rl::Shader::Shader(std::string const &name) : ::Shader{}, _isLoaded(true) {};

int rl::Shader::getLocation(std::string uniformName)
{
    return ::GetShaderLocation(*this, uniformName.c_str());
}

int rl::Shader::getLocationAttrib(std::string attribName)
{
    return ::GetShaderLocationAttrib(*this, attribName.c_str());
}

void rl::Shader::setValue(int locIndex, const void *value, int uniformType)
{
    ::SetShaderValue(*this, locIndex, value, uniformType);
}

void rl::Shader::setValueV(int locIndex, const void *value, int uniformType, int count)
{
    ::SetShaderValueV(*this, locIndex, value, uniformType, count);
}

void rl::Shader::setValueMatrix(int locIndex, Matrix mat)
{
    ::SetShaderValueMatrix(*this, locIndex, mat);
}

void rl::Shader::setValueTexture(int locIndex, Texture2D texture)
{
    ::SetShaderValueTexture(*this, locIndex, texture);
}

void rl::Shader::unload()
{
    ::UnloadShader(*this);
    this->_isLoaded = false;
}

// template <>
// void rl::ShaderManager::insertData(rl::Shader const &shader, std::string const &name)
// {
//     if (this->_datas.find(name) != this->_datas.end()) {
//         throw(rl::Error("Shader \"" + name + "\" already exists.", "ShaderManager::insertData"));
//     }
//     this->_datas.insert(std::make_pair(name, shader));
// }
