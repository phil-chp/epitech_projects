/*
** EPITECH PROJECT, 2022
** RType
** File description:
** UI.hpp
*/

#pragma once

#include "GameEngine/Entity.hpp"
#include "ECS/Coordinator.hpp"
#include "ECS/Components/UI.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"
#include "Lib/Raylib/rl-cpp/Textures/Textures.hpp"

namespace engine {
class UI : public engine::Entity{
public:
        UI() : Entity(){
                ::rl::Text txt(
                        std::string(""),
                        engine::FontManager::getInstance().getData(engine::FontType::FONT_UI),
                        15,
                        ::rl::Color(255,255,255,255),
                        ::rl::Vector2(0, 0)
                );
                ::rl::Texture icons(SpriteManager::getInstance().getData(SpriteType::SPR_UI_ICONS));
                icons.animRect = ::game::Rect (0, 0, 150 * .4, 155 * .4);
                // std::cout << "Icon Size: " << icons.getSize().x << ", "  << icons.getSize().y << std::endl;
                icons.setSize(::game::Vector2(icons.getSize()) * .4);
                // std::cout << "Icon after Size: " << icons.getSize().x << ", "  << icons.getSize().y << std::endl;
                // icons.animRect = ::game::Rect ();

                ::rl::Texture heart(SpriteManager::getInstance().getData(SpriteType::SPR_UI_HEART));
                heart.animRect = ::game::Rect (0, 0, 50 * .6, 44 * .59);
                heart.setSize(::game::Vector2(heart.getSize()) * .6);

                ::ecs::Coordinator::getInstance().addComponent(
                        this->entity,
                        ecs::UI {
                                .maxPlayer = 4,
                                .mainPlayer = 1,
                                .playerPos = {{30, 20}, {530, 20}, {1030, 20}, {1530, 20}},
                                .score = {0, 0, 0, 0},
                                .life = {4, 4, 4, 4},
                                .weaponId = 0,
                                .charge = 0,
                                .heartAnimFrame = 0,
                                .heartAnimDelay = 0.2,
                                .heartAnimActualDelay = 0.2,
                                .iconOffset = {0, 0},
                                .nameOffset = {70, 27},
                                .scoreOffset = {230, 27},
                                .lifeOffset = {150, 25},
                                .weapOffset = {340, 27},
                                .txt = ::rl::Text(
                                        std::string(""),
                                        engine::FontManager::getInstance().getData(engine::FontType::FONT_UI),
                                        15,
                                        ::rl::Color(255,255,255,255),
                                        ::rl::Vector2(0, 0)
                                ),
                                .heart = heart,
                                .icon = icons
                });
        }
        ~UI() = default;
private:
    };
}
