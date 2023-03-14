// /*
// ** EPITECH PROJECT, 2022
// ** RType
// ** File description:
// ** RLShader
// */


#include "ECS/Components/RLShader.hpp"
#include "ECS/Components/RLDrawable.hpp"
#include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
#include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
#include "ECS/Coordinator.hpp"

template <>
void  ecs::RLShader::update(ecs::Entity ent, float dt)
{
    this->upd(ent, dt);
}

template<>
void ecs::RLShader::draw()
{
    std::vector<ecs::Entity> toRm;
    ::rl::Window::getInstance().beginShaderMode(this->_shader);
    if (this->background == true) {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
    }
    else {
        for (ecs::Entity entity : this->_entities) {
            ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
            if (!drawable.shadered) {
                toRm.push_back(entity);
            } else {
                Transform &transform = ecs::Coordinator::getInstance().getComponent<Transform>(entity);
                drawable.drawRec(transform.position);
            }
        }
    }
    ::rl::Window::getInstance().endShaderMode();
    for (ecs::Entity entity : toRm) {
        remove_if(this->_entities.begin(), this->_entities.end(), [entity](ecs::Entity e) {
                return (e == entity);
        });
    }
}



// template<>
// void ecs::RLShader::update(float dt)
// {
//     // this->upd(ent, _particles, dt);
// }
