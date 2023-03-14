/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Drawable
*/


#ifndef DRAWABLE_BUTTON_WIDGET_HPP_
    #define DRAWABLE_BUTTON_WIDGET_HPP_

    #include "Raylib.hpp"

namespace ecs {
    struct DrawableButtonWidget {
        void draw(ButtonWidget const &widget, rl::Vector2 const &pos, rl::Vector2 const &size) {
            (void)size;
            static rl::Texture button(rl::TEXTURE_BUTTON);
            static rl::Text text(widget.content, 50, rl::RL_BLACK);

            //TODO: implement //TODO: fun
            // static rl::Texture button(rl::TextureManager::getInstance().getDatas("button name"));
            //std::cout << "PRE button size : [" << size.x << ", " << size.y << "]" << std::endl;
            // button.width *= size.x/button.width;
            // button.height *= size.y/button.height;
            //button.setSize(size);
            // std::cout << "POST button size : [" << button.getWidth() << ", " << button.getHeight() << "]" << std::endl;
            float frameHeight = button.getHeight() / 3;
            float spriteCount = button.getWidth()  / 4;
            rl::Rectangle sourceRect(spriteCount * (int)widget.type, 0, spriteCount, frameHeight);

            sourceRect.y = 0;
            if (widget.clicked) {
                sourceRect.y = frameHeight * 2;
            } else if (widget.hover) {
                sourceRect.y = frameHeight;
            }
            button.drawRec(sourceRect, pos);

            if (widget.type == ecs::buttonType::DEFAULT) {
                text.setText(widget.content);
                rl::Vector2 vec = {
                    pos.x + size.x / 2 - text.getLength() * text.getFontSize() / 4,
                    pos.y + size.y / 2 - text.getFontSize() / 2
                };
                text.position = vec;
                text.draw();
            }
        }
    };
}

#endif /* !DRAWABLEWIDGET_HPP_ */
