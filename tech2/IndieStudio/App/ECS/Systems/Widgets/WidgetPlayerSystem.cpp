/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetPlayerSystem
*/

#include "WidgetPlayerSystem.hpp"

void ecs::WidgetPlayerSystem::selectionPlayer(PlayerWidget &widget) const {
    if (widget.mode != SELECT_NEXT && widget.mode != SELECT_PREV) return;
    if (widget.mode == SELECT_NEXT) {
        rl::SoundManager::getInstance().getData(rl::SOUND_CRATE_BURN).play();
        widget.indexPlayerColor++;
    } else if (widget.mode == SELECT_PREV) {
        rl::SoundManager::getInstance().getData(rl::SOUND_CRATE_BURN).play();
        widget.indexPlayerColor--;
    }
    if (widget.indexPlayerColor > (MAX_COLOR_PLAYER - 1)) {
        widget.indexPlayerColor = 0;
    } else if (widget.indexPlayerColor < 0) {
        widget.indexPlayerColor = (MAX_COLOR_PLAYER - 1);
    }
    widget.playerColor = this->_playerColors[widget.indexPlayerColor];
    widget.mode = LOGIN;  
}

void ecs::WidgetPlayerSystem::setPlayerMode(PlayerWidget &widget) const {
    for (size_t i = 0; i < widget.keys.size(); i++) {
        if (rl::Keyboard::isKeyPressed(widget.keys[i]) && widget.mode != LOGOUT) {
            widget.mode = static_cast<State>(i);
        } else if (rl::Keyboard::isKeyPressed(widget.keys[i]) && widget.mode == LOGOUT) {
            widget.mode = LOGIN;
            widget.content.erase(
                std::remove(widget.content.begin(), widget.content.end(), '?'),
                widget.content.end());
        }
    }
}

void ecs::WidgetPlayerSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        PlayerWidget &widget = ecs::Coordinator::getInstance().getComponent<PlayerWidget>(entity);
        Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);

        if (rl::Mouse::isButtonPressed(MOUSE_BUTTON_LEFT)) {
            rl::Rectangle rect(trans.position, trans.scale);
            bool clicked = rect.CheckCollisionPointRec(rl::Window::getInstance().getMousePosition());

            if (widget.mode == LOGOUT && clicked) {
                rl::SoundManager::getInstance().getData(rl::SOUND_PLAYER_SELECT_JOIN).play();
                widget.mode = LOGIN;
                widget.action();
                widget.content.erase(
                    std::remove(widget.content.begin(), widget.content.end(), '?'),
                    widget.content.end());
            } else if ((widget.mode == LOGIN || widget.mode == READY) && clicked) {
                widget.mode = LOGOUT;
                widget.action();
                widget.content += "?";
            }
        }
        if (widget.mode == LOGIN && rl::Keyboard::isKeyPressed(widget.keys[LOGOUT])) {
            widget.content += "?";
        }
        this->setPlayerMode(widget);
        this->selectionPlayer(widget);
    }
}
