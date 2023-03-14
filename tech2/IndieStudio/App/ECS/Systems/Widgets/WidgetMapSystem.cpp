/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetMapSystem
*/

#include "WidgetMapSystem.hpp"

void ecs::WidgetMapSystem::selectionMap(MapWidget &widget) const {
    if (widget.mode != SELECT_NEXT && widget.mode != SELECT_PREV) return;
    if (widget.mode == SELECT_NEXT) {
        widget.indexMapColor++;
    } else if (widget.mode == SELECT_PREV) {
        widget.indexMapColor--;
    }
    if (widget.indexMapColor > (MAX_MAP - 1)) {
        widget.indexMapColor = 0;
    } else if (widget.indexMapColor < 0) {
        widget.indexMapColor = (MAX_MAP - 1);
    }
    widget.mapColor = this->_mapColors[widget.indexMapColor];
    widget.mode = LOGIN;
}

void ecs::WidgetMapSystem::setMapMode(MapWidget &widget) const {
    for (size_t i = 0; i < widget.keys.size(); i++) {
        if (rl::Keyboard::isKeyPressed(widget.keys[i]) && widget.mode != LOGOUT) {
            widget.mode = static_cast<State>(i);
        } else if (rl::Keyboard::isKeyPressed(widget.keys[i]) && widget.mode == LOGOUT) {
            widget.mode = LOGIN;
        }
    }
}

void ecs::WidgetMapSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        MapWidget &widget = ecs::Coordinator::getInstance().getComponent<MapWidget>(entity);
        Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);

        if (rl::Mouse::isButtonPressed(MOUSE_BUTTON_LEFT)) {
            rl::Rectangle rect(trans.position, trans.scale);
            bool clicked = rect.CheckCollisionPointRec(rl::Window::getInstance().getMousePosition());

            if (widget.mode == LOGOUT && clicked) {
                widget.mode = LOGIN;
            } else if (widget.mode == READY && clicked) {
                widget.mode = LOGOUT;
            }
        }
        this->setMapMode(widget);
        this->selectionMap(widget);
        widget.content = "MAP:" + std::to_string(widget.indexMapColor + 1);
        if (widget.mode == LOGIN) {
            widget.action();
        }
    }
}
