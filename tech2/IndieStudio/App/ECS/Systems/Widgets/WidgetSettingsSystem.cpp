/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** WidgetSettingsSystem
*/

#include "WidgetSettingsSystem.hpp"

void ecs::WidgetSettingsSystem::setWidgetKey(ControlWidget &widget, uint8_t indexPlayer) const {
    if (widget.indexKey == 99) return;
    widget.key = SettingsManager::getInstance().getPlayerKeys(indexPlayer)[widget.indexKey];
}

void ecs::WidgetSettingsSystem::setNewKey(ControlWidget &widget, rl::KeyboardKeys const &newKey) const {
    //if (!widget.isPressed) return;

    SettingsManager::getInstance().setKey(widget.indexPlayer, static_cast<KeyPlayer>(widget.indexKey), newKey);
    widget.key = newKey;
    widget.isPressed = false;
}

void ecs::WidgetSettingsSystem::update(float dt) const {
    (void)dt;
    rl::KeyboardKeys key = (rl::KeyboardKeys)(rl::Keyboard::getKeyPressed());
    for (ecs::Entity const &entity : this->entities) {
        ControlWidget &widget = ecs::Coordinator::getInstance().getComponent<ControlWidget>(entity);
        Transform2D &trans = ecs::Coordinator::getInstance().getComponent<Transform2D>(entity);
        static uint8_t indexPlayer = widget.indexPlayer;
        setWidgetKey(widget, indexPlayer);
        if (rl::Mouse::isButtonPressed(MOUSE_BUTTON_LEFT)) {
            rl::Rectangle rect(trans.position, trans.scale);
            bool clicked = rect.CheckCollisionPointRec(rl::Window::getInstance().getMousePosition());

            if (widget.type == KEY) {
                if (clicked) widget.isPressed = !widget.isPressed;
                else widget.isPressed = false;
            } else if (widget.type == PLAYER_SELECT) {
                if (clicked) {
                    widget.isPressed = false;
                    indexPlayer = widget.indexPlayer;
                }
            } else if (widget.type == SOUND || widget.type == MUSIC || widget.type == EXIT) {
                if (clicked) {
                    widget.action();
                }
            }
        }
        if (widget.type == SOUND_INFO) {
            widget.content = std::to_string(SettingsManager::getInstance().getSoundVolume());
        } else if (widget.type == MUSIC_INFO) {
            widget.content = std::to_string(SettingsManager::getInstance().getMusicVolume());
        }
        if (widget.type == KEY) {
            widget.indexPlayer = indexPlayer;
            if (widget.isPressed && (key != 0)) {
                setNewKey(widget, key);
            } else if (rl::Keyboard::isKeyPressed(widget.key)) {
                widget.isPressed = !widget.isPressed;
            }
        }
    }
}
