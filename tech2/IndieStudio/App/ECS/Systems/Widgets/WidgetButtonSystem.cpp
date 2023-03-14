/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetButtonSystem
*/

#include "WidgetButtonSystem.hpp"

void ecs::WidgetButtonSystem::update(float dt) const {
    (void)dt;
    for (ecs::Entity const &entity : this->entities) {
        ecs::ButtonWidget &widget = ecs::Coordinator::getInstance().getComponent<ButtonWidget>(entity);
        ecs::Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);
        rl::Rectangle rect(trans.position, trans.scale);

        /* GESTURES MOUSE */
        if (rect.CheckCollisionPointRec(rl::Window::getInstance().getMousePosition())) {
            widget.hover = true;
            if (rl::Mouse::isButtonPressed(MOUSE_BUTTON_LEFT)) {
                rl::SoundManager::getInstance().getData(rl::SOUND_BUTTON_PRESS).play();
                widget.clicked = true;
            }
            widget.released = rl::Mouse::isButtonReleased(MOUSE_BUTTON_LEFT);
        } else {
            widget.hover = false;
            widget.clicked = false;
        }
        if (widget.released) {
            widget.action();
        }
    }
}
