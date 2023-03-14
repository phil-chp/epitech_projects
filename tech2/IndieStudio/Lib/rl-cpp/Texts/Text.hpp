/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_

    #include "Raylib-cpp.hpp"
    #include "Font/Font.hpp"
    #include "Vectors/Vector2.hpp"
    #include "Colors/Colors.hpp"
    #include "rlgl.h"
    #include <iostream>
    #include "Drawable/IDrawable.hpp"
    #define LETTER_BOUNDRY_SIZE     0.25f
    #define TEXT_MAX_LAYERS         32
    #define LETTER_BOUNDRY_COLOR    VIOLET

namespace rl {
    class Text : public IDrawable {
        public:
            Text(std::string const &text = "",
                 Font const &font = Font("Assets/fonts/Oretans-Shadow.ttf"),
                 int fontSize = 35,
                 Color const &color = RL_BLACK)
                : position(), _font(font), _text(text), _fontSize(fontSize), _color(color) {}
            explicit Text(std::string const &text,
                 std::string const &FontFile = "Assets/fonts/Oretans-Shadow.ttf",
                 int fontSize = 35,
                 Color const &color = RL_BLACK)
                : position(), _font(FontFile), _text(text), _fontSize(fontSize), _color(color) {}
            explicit Text(std::string const &text,
                          int fontSize = 35,
                          Color const &color = RL_BLACK)
                : position(), _font(), _text(text), _fontSize(fontSize), _color(color) {}
            explicit Text(std::string const &text,
                 std::string const &FontFile = "Assets/fonts/Oretans-Shadow.ttf",
                 int fontSize = 35,
                 Color const &color = RL_BLACK,
                 Vector2 const &Pos = {0, 0})
                : position(Pos), _font(FontFile), _text(text), _fontSize(fontSize), _color(color) {}

            ~Text() = default;

        //* Custom ---------------------------------------------------------- //

            void setText(std::string const &text);
            void setFont(Font const &font);
            void setFontSize(int fontSize);
            void setColor(Color const &color);

            std::string getText() const;
            Font getFont() const;
            int getFontSize() const;
            int getLength() const {
                return (this->_text.length());
            }
            Color getColor() const;

        //* Built-in -------------------------------------------------------- //

            // Draw text with basic settings
            void draw() const override;
            // Draw text using font and additional parameters
            void drawEx(Vector2 const &position, float fontSize, float spacing, Color const &tint);
            // Draw text using Font and pro parameters (rotation)
            // void drawPro(Vector2 const &origin, float rotation, float fontSize, float spacing, Color const &tint);
            void drawPro(Vector2 const &origin = Vector2(0), float rotation = 0.0f, float fontSize = 4.0f, float spacing = 1.0f, Color const &tint = RL_BLACK);
            // Draw one character (codepoint)
            void drawCodepoint(int codepoint, Vector2 const &position, float fontSize, Color const &tint);
            // Draw text 3D
            void draw3D(Vector3 const &position = Vector3(0), float fontSpacing = 1.0f, float lineSpacing = 1.0f, bool horizontal = false, bool backface = false);

            Vector2 position;

        private:
            void drawCodepoint3D(int codepoint, Vector3 position, bool backface);
            // ::Vector3 measureText3D(::Font font, const char* text, float fontSize, float fontSpacing, float lineSpacing);
            Font        _font;
            std::string _text;
            int         _fontSize;
            Color       _color;

    };
}

#endif /* !TEXT_HPP_ */
