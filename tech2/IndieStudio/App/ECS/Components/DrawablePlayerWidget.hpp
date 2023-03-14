/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Drawable
*/

#ifndef DRAWABLE_PLAYER_WIDGET_HPP_
    #define DRAWABLE_PLAYER_WIDGET_HPP_
    #include "Raylib.hpp"
    #include <unordered_map>
    #include <vector>

namespace ecs {
    struct DrawablePlayerWidget {
        DrawablePlayerWidget() {
            this->_colorBrightness.insert(std::make_pair(rl::RL_WHITE.serialize(),  rl::Color::getBrightness(rl::RL_WHITE)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_BLACK.serialize(),  rl::Color::getBrightness(rl::RL_BLACK)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_RED.serialize(),    rl::Color::getBrightness(rl::RL_RED)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_GREEN.serialize(),  rl::Color::getBrightness(rl::RL_GREEN)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_BLUE.serialize(),   rl::Color::getBrightness(rl::RL_BLUE)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_YELLOW.serialize(), rl::Color::getBrightness(rl::RL_YELLOW)));

            this->_colorPlayerStatus.insert(std::make_pair(rl::RL_DARKGRAY.serialize(),  rl::Color::getBrightness(rl::RL_DARKGRAY)));
            this->_colorPlayerStatus.insert(std::make_pair(rl::RL_LIGHTGRAY2.serialize(), rl::Color::getBrightness(rl::RL_LIGHTGRAY2)));
            this->_colorPlayerStatus.insert(std::make_pair(rl::RL_DARKRED.serialize(),    rl::Color::getBrightness(rl::RL_DARKRED)));
            this->_colorPlayerStatus.insert(std::make_pair(rl::RL_DARKGREEN.serialize(),  rl::Color::getBrightness(rl::RL_DARKGREEN)));
            this->_colorPlayerStatus.insert(std::make_pair(rl::RL_DARKBLUE.serialize(),   rl::Color::getBrightness(rl::RL_DARKBLUE)));
            this->_colorPlayerStatus.insert(std::make_pair(rl::RL_DARKYELLOW.serialize(), rl::Color::getBrightness(rl::RL_DARKYELLOW)));

            this->_colorPlayerStatusBackground = {
                rl::RL_LIGHTGRAY2,
                rl::RL_LIGHTGRAY,
                rl::RL_DARKRED,
                rl::RL_DARKGREEN,
                rl::RL_DARKBLUE,
                rl::RL_DARKYELLOW
            };
        };
        ~DrawablePlayerWidget() = default;
        void drawPlayerWidgetStatus(ecs::PlayerWidget const &widget, rl::Vector2 const &pos, rl::Vector2 const &size) {
            static rl::Vector2 statusPos(pos.x, pos.y + 338);
            static rl::Vector2 statusSize(size.x, size.y / 4);
            static rl::Rectangle status(statusPos, statusSize);
            static rl::Text text(widget.content, 50, rl::RL_BLACK);

            statusPos = rl::Vector2(pos.x, pos.y + 338);
            statusSize = rl::Vector2(size.x, size.y / 4);
            status.setPosition(statusPos);
            status.setSize(statusSize);
            status.color = widget.mode == READY ? rl::RL_DARKBLUE : (widget.mode == LOGOUT ? rl::RL_DARKGRAY : this->_colorPlayerStatusBackground[widget.indexPlayerColor]);
            text.setText(widget.mode == READY ? "OK!!" : (widget.mode == LOGOUT ? "ORDI" : widget.content));
            text.setColor(widget.mode == READY || widget.mode == LOGOUT ? rl::RL_WHITE :
                (this->_colorPlayerStatus[this->_colorPlayerStatusBackground[widget.indexPlayerColor].serialize()] < 0.5 ? rl::RL_BLACK : rl::RL_WHITE));
            text.position = rl::Vector2(
                    statusPos.x + statusSize.x / 2 - text.getLength() * text.getFontSize() / 4,
                    statusPos.y + statusSize.y / 2 - text.getFontSize() / 2);
            status.draw();
            text.draw();
        }

        void draw(PlayerWidget &widget, rl::Vector2 const &pos, rl::Vector2 const &size) {
            // static int space = pos.y;
            static rl::Rectangle drawable(pos, size);
            static rl::Rectangle wides(rl::Vector2(pos.x - 3, pos.y - 3), rl::Vector2(size.x + 6, size.y + 6), rl::RL_BLACK);
            static rl::Text text(widget.content, 50, rl::RL_BLACK);

            drawable.color = (widget.mode == READY ? rl::RL_SKYBLUE : (widget.mode == LOGOUT ? rl::RL_LIGHTGRAY
                                                                                          : widget.playerColor));
            drawable.setPosition(pos);
            wides.setPosition(rl::Vector2(pos.x - 3, pos.y - 3));
            drawable.setSize(size);
            wides.setSize(rl::Vector2(size.x + 6, size.y + 6));
            if (widget.mode == LOGOUT || widget.mode == READY) text.setColor(rl::RL_BLACK);
            else text.setColor((this->_colorBrightness[widget.playerColor.serialize()] < 0.5f) ? rl::RL_WHITE : rl::RL_BLACK);
            text.setText(widget.content);
            text.position = rl::Vector2(
                    pos.x + size.x / 2 - text.getLength() * text.getFontSize() / 4,
                    pos.y + size.y / 2 - text.getFontSize() / 2);
            wides.draw();
            drawable.draw();
            text.draw();
            drawPlayerWidgetStatus(widget, pos, size);
        }

        private:
            std::unordered_map<std::string, float> _colorBrightness;
            std::map<std::string, float> _colorPlayerStatus;
            std::array<rl::Color, 6> _colorPlayerStatusBackground;
    };
}

#endif /* !DRAWABLE_PLAYER_WIDGET_HPP_ */
