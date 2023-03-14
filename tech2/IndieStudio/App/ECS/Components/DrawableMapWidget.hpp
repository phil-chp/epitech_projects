/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Drawable
*/

#ifndef DRAWABLE_MAP_WIDGET_HPP_
    #define DRAWABLE_MAP_WIDGET_HPP_
    #include "Raylib.hpp"
    #include <unordered_map>
    #include <vector>

namespace ecs {
    struct DrawableMapWidget {
        DrawableMapWidget() {
            this->_colorBrightness.insert(std::make_pair(rl::RL_PURPLE.serialize(),  rl::Color::getBrightness(rl::RL_PURPLE)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_MAGENTA.serialize(),  rl::Color::getBrightness(rl::RL_MAGENTA)));
            this->_colorBrightness.insert(std::make_pair(rl::RL_GREEN.serialize(),    rl::Color::getBrightness(rl::RL_GREEN)));

            this->_colorMapStatus.insert(std::make_pair(rl::RL_DARKPURPLE.serialize(),  rl::Color::getBrightness(rl::RL_DARKPURPLE)));
            this->_colorMapStatus.insert(std::make_pair(rl::RL_DARKMAGENTA.serialize(), rl::Color::getBrightness(rl::RL_DARKMAGENTA)));
            this->_colorMapStatus.insert(std::make_pair(rl::RL_DARKGREEN.serialize(),    rl::Color::getBrightness(rl::RL_DARKGREEN)));

            this->_colorMapStatusBackground = {
                rl::RL_DARKPURPLE,
                rl::RL_DARKMAGENTA,
                rl::RL_DARKGREEN,
            };
        };
        ~DrawableMapWidget() = default;
        void drawTitle() {
            static rl::Text text("Select Your Map", 50, rl::RL_BLACK);
            // TODO: should get the middle of the screen
            text.position = rl::Vector2{static_cast<float>(rl::Window::getInstance().getWidth()) / 2 - text.getLength() * text.getFontSize() / 4, 50};
            text.draw();
        }

        void drawMapWidgetStatus(ecs::MapWidget const &widget, rl::Vector2 const &pos, rl::Vector2 const &size) {
            static rl::Vector2 statusPos(pos.x, pos.y);
            static rl::Vector2 statusSize(size.x, size.y / 4);
            static rl::Rectangle status(statusPos, statusSize);
            static rl::Text text(widget.content, 50, rl::RL_BLACK);

            statusPos = rl::Vector2(pos.x, pos.y);
            statusSize = rl::Vector2(size.x, size.y / 4);
            status.setPosition(statusPos);
            status.setSize(statusSize);
            status.color = widget.mode == READY ? rl::RL_DARKBLUE : this->_colorMapStatusBackground[widget.indexMapColor];
            text.setText(widget.mode == READY ? "OK!!" : widget.content);
            text.setColor(widget.mode == READY ? rl::RL_WHITE :
                (this->_colorMapStatus[this->_colorMapStatusBackground[widget.indexMapColor].serialize()] < 0.5 ? rl::RL_BLACK : rl::RL_WHITE));
            text.position = rl::Vector2(
                    statusPos.x + statusSize.x / 2 - text.getLength() * text.getFontSize() / 4,
                    statusPos.y + statusSize.y / 2 - text.getFontSize() / 2);
            status.draw();
            text.draw();
        }

        void draw(MapWidget &widget, rl::Vector2 const &pos, rl::Vector2 const &size) {
            // static int space = pos.y;
            static rl::Rectangle drawable(pos, size);
            static rl::Rectangle wides(rl::Vector2(pos.x - 3, pos.y - 3), rl::Vector2(size.x + 6, size.y + 6), rl::RL_BLACK);
            static rl::Text text(widget.content, 50, rl::RL_BLACK);

            drawable.color = (widget.mode == READY ? rl::RL_SKYBLUE : widget.mapColor);
            drawable.setPosition(pos);
            wides.setPosition(rl::Vector2(pos.x - 3, pos.y - 3));
            drawable.setSize(size);
            wides.setSize(rl::Vector2(size.x + 6, size.y + 6));
            if (widget.mode == LOGOUT || widget.mode == READY) text.setColor(rl::RL_BLACK);
            else text.setColor((this->_colorBrightness[widget.mapColor.serialize()] < 0.5f) ? rl::RL_WHITE : rl::RL_BLACK);
            text.setText(widget.content);
            text.position = rl::Vector2(
                    pos.x + size.x / 2 - text.getLength() * text.getFontSize() / 4,
                    pos.y + size.y / 2 - text.getFontSize() / 2);
            wides.draw();
            drawable.draw();
            text.draw();
            this->drawTitle();
            this->drawMapWidgetStatus(widget, pos, size);
        }

        private:
            std::unordered_map<std::string, float> _colorBrightness;
            std::map<std::string, float> _colorMapStatus;
            std::array<rl::Color, 6> _colorMapStatusBackground;
    };
}

#endif /* !DRAWABLE_MAP_WIDGET_HPP_ */
