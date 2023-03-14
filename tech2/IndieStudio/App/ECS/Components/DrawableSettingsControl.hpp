/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Drawable
*/

#ifndef DRAWABLE_SETTINGS_HPP_
    #define DRAWABLE_SETTINGS_HPP_

    #include "Raylib.hpp"
    #include "ControlWidget.hpp"
    #include <unordered_map>
    #include <vector>

namespace ecs {
    struct DrawableSettingsControl {
        DrawableSettingsControl() {
            this->_colorBackgroundPressed = {
                    rl::RL_DARKBLUE,
                    rl::RL_DARKGREEN,
                    rl::RL_DARKPURPLE,
                    rl::RL_DARKYELLOW,
                    rl::RL_DARKPURPLE,
                    rl::RL_DARKMAGENTA
            };

            this->_colorBackground = {
                    rl::RL_BLUE,
                    rl::RL_GREEN,
                    rl::RL_PURPLE,
                    rl::RL_YELLOW,
                    rl::RL_PURPLE,
                    rl::RL_MAGENTA
            };
        };
        ~DrawableSettingsControl() = default;
        void drawTitle() {
            static rl::Text text("SETTINGS", 50, rl::RL_BLACK);
            text.position = rl::Vector2{static_cast<float>(rl::Window::getInstance().getWidth()) / 2 - text.getLength() * text.getFontSize() / 4, 50};
            text.draw();
        }

        void draw(ControlWidget const &widget, rl::Vector2 const &pos, rl::Vector2 const &size) {
            std::string str = rl::KeyboardKeysString[widget.key];
            if (str.empty() && widget.type == PLAYER_SELECT) str = "P" + std::to_string(widget.indexPlayer + 1);
            else if (widget.type != PLAYER_SELECT && widget.type != KEY) str = widget.content;
            static rl::Rectangle drawable(pos, size);
            static rl::Rectangle wides(rl::Vector2(pos.x - 3, pos.y - 3), rl::Vector2(size.x + 6, size.y + 6), rl::RL_BLACK);
            static rl::Text text(str, 50, rl::RL_BLACK);
            if (widget.type == MUSIC)
                drawable.color = rl::RL_SKYBLUE;
            else if (widget.type == SOUND)
                drawable.color = rl::RL_BEIGE;
            else drawable.color = (widget.isPressed ? this->_colorBackgroundPressed[widget.indexPlayer] : this->_colorBackground[widget.indexPlayer]);
            drawable.setPosition(pos);
            wides.setPosition(rl::Vector2(pos.x - 3, pos.y - 3));
            drawable.setSize(size);
            wides.setSize(rl::Vector2(size.x + 6, size.y + 6));
            text.setText(str);
            text.position = rl::Vector2(
                    pos.x + size.x / 2 - text.getLength() * text.getFontSize() / 4,
                    pos.y + size.y / 2 - text.getFontSize() / 2);

            if (widget.type != SOUND_INFO && widget.type != MUSIC_INFO && widget.type != TITLE) {
                wides.draw();
                drawable.draw();
            }
            text.draw();
            this->drawTitle();
        }
    private:
        std::array<rl::Color, 6> _colorBackground;
        std::array<rl::Color, 6> _colorBackgroundPressed;
    };
}

#endif /* !DRAWABLE_SETTINGS_HPP_ */
