/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Text
*/

#include "Text.hpp"

// SETTERS ------------------------------------------------------------------ //

void rl::Text::setText(std::string const &text)
{
    this->_text = text;
}

void rl::Text::setFont(rl::Font const &font)
{
    this->_font = font;
}

void rl::Text::setFontSize(int fontSize)
{
    this->_fontSize = fontSize;
}

void rl::Text::setColor(rl::Color const &color)
{
    this->_color = color;
}

// GETTERS ------------------------------------------------------------------ //

std::string rl::Text::getText() const
{
    return (this->_text);
}

rl::Font rl::Text::getFont() const
{
    return (this->_font);
}

int rl::Text::getFontSize() const
{
    return (this->_fontSize);
}

rl::Color rl::Text::getColor() const
{
    return (this->_color);
}

// TEXT --------------------------------------------------------------------- //

void rl::Text::draw() const
{
    ::DrawText(
        this->_text.c_str(),
        this->position.x,
        this->position.y,
        this->_fontSize,
        this->_color
    );
}

void rl::Text::drawEx(rl::Vector2 const &position,
                      float fontSize,
                      float spacing,
                      rl::Color const &tint)
{
    ::DrawTextEx(
        this->_font,
        this->_text.c_str(),
        position,
        fontSize,
        spacing,
        tint
    );
}

void rl::Text::drawPro(rl::Vector2 const &origin,
                       float rotation,
                       float fontSize,
                       float spacing,
                       rl::Color const &tint)
{
    ::DrawTextPro(
        this->_font,
        this->_text.c_str(),
        this->position,
        origin,
        rotation,
        fontSize,
        spacing,
        tint
    );
}

void rl::Text::drawCodepoint(int codepoint,
                             rl::Vector2 const &position,
                             float fontSize,
                             rl::Color const &tint)
{
    ::DrawTextCodepoint(
        this->_font,
        codepoint,
        position,
        fontSize,
        tint
    );
}

void rl::Text::draw3D(rl::Vector3 const &position,
                      float fontSpacing,
                      float lineSpacing,
                      bool horizontal,
                      bool backface)
{
    // Vector3 pos = this->measureText3D(this->_font, this->_text.data(), fontSpacing, lineSpacing, horizontal);
    // pos.x = position.x - pos.x;
    // pos.y = position.y - pos.y;
    // pos.z = position.z - pos.z;

    if (horizontal) {
        rlPushMatrix();
        {
            rlRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            rlRotatef(90.0f, 0.0f, 0.0f, -1.0f);
        }
    }

    int length = TextLength(this->_text.c_str());
    float textOffsetY = 0.0f;
    float textOffsetX = 0.0f;
    float scale = this->_fontSize / (float)this->_font.baseSize;

    for (int i = 0; i < length; ) {
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&this->_text[i], &codepointByteCount);
        int index = GetGlyphIndex(this->_font, codepoint);

        if (codepoint == 0x3f) {
            codepointByteCount = 1;
        }
        if (codepoint == '\n') {
            textOffsetY += scale + lineSpacing / (float)this->_font.baseSize * scale;
            textOffsetX = 0.0f;
        } else {
            if ((codepoint != ' ') && (codepoint != '\t')) {
                this->drawCodepoint3D(codepoint, (Vector3){position.x + textOffsetX, position.y, position.z + textOffsetY}, backface);
            }

            // if (this->_font.glyphs[index].advanceX == 0) {
            //     textOffsetX += (float)(this->_font.recs[index].width + fontSpacing) / (float)this->_font.baseSize * scale;
            // } else {
            //     textOffsetX += (float)(this->_font.glyphs[index].advanceX + fontSpacing) / (float)this->_font.baseSize * scale;
            // }
            textOffsetX += (this->_font.glyphs[index].advanceX == 0
                ? (float)(this->_font.recs[index].width + fontSpacing)      / (float)this->_font.baseSize * scale
                : (float)(this->_font.glyphs[index].advanceX + fontSpacing) / (float)this->_font.baseSize * scale);
        }
        i += codepointByteCount;
    }
    if (horizontal) rlPopMatrix();
}

void rl::Text::drawCodepoint3D(int codepoint, Vector3 position, bool backface)
{
    // Character index position in sprite font
    // NOTE: In case a codepoint is not available in the font, index returned points to '?'
    int index = GetGlyphIndex(this->_font, codepoint);
    float scale = this->_fontSize / (float)this->_font.baseSize;

    // Character destination rectangle on screen
    // NOTE: We consider charsPadding on drawing
    position.x += (float)(this->_font.glyphs[index].offsetX - this->_font.glyphPadding) / (float)this->_font.baseSize * scale;
    position.z += (float)(this->_font.glyphs[index].offsetY - this->_font.glyphPadding) / (float)this->_font.baseSize * scale;

    // Character source rectangle from font texture atlas
    // NOTE: We consider chars padding when drawing, it could be required for outline/glow shader effects
    Rectangle srcRec = {
        this->_font.recs[index].x - (float)this->_font.glyphPadding,
        this->_font.recs[index].y - (float)this->_font.glyphPadding,
        this->_font.recs[index].width  + 2.0f * this->_font.glyphPadding,
        this->_font.recs[index].height + 2.0f * this->_font.glyphPadding
    };

    float width  = (float)(this->_font.recs[index].width  + 2.0f * this->_font.glyphPadding) / (float)this->_font.baseSize * scale;
    float height = (float)(this->_font.recs[index].height + 2.0f * this->_font.glyphPadding) / (float)this->_font.baseSize * scale;

    if (this->_font.texture.id > 0) {
        const float x = 0.0f;
        const float y = 0.0f;
        const float z = 0.0f;

        // normalized texture coordinates of the glyph inside the this->_font texture (0.0f -> 1.0f)
        const float tx = srcRec.x / this->_font.texture.width;
        const float ty = srcRec.y / this->_font.texture.height;
        const float tw = (srcRec.x + srcRec.width)  / this->_font.texture.width;
        const float th = (srcRec.y + srcRec.height) / this->_font.texture.height;

        rlCheckRenderBatchLimit(4 + 4 * backface);
        rlSetTexture(this->_font.texture.id);

        rlPushMatrix();
        {
            rlTranslatef(position.x, position.y, position.z);

            rlBegin(RL_QUADS);
            {
                rlColor4ub(this->_color.r, this->_color.g, this->_color.b, this->_color.a);

                // Front Face
                rlNormal3f(0.0f, 1.0f, 0.0f);                                   // Normal Pointing Up
                rlTexCoord2f(tx, ty); rlVertex3f(x,         y, z);              // Top Left Of The Texture and Quad
                rlTexCoord2f(tx, th); rlVertex3f(x,         y, z + height);     // Bottom Left Of The Texture and Quad
                rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height);     // Bottom Right Of The Texture and Quad
                rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);              // Top Right Of The Texture and Quad

                if (backface) {
                    // Back Face
                    rlNormal3f(0.0f, -1.0f, 0.0f);                              // Normal Pointing Down
                    rlTexCoord2f(tx, ty); rlVertex3f(x,         y, z);          // Top Right Of The Texture and Quad
                    rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);          // Top Left Of The Texture and Quad
                    rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height); // Bottom Left Of The Texture and Quad
                    rlTexCoord2f(tx, th); rlVertex3f(x,         y, z + height); // Bottom Right Of The Texture and Quad
                }
            }
            rlEnd();
        }
        rlPopMatrix();
        rlSetTexture(0);
    }
}

// Vector3 rl::Text::measureText3D(Font font, const char* text, float fontSize, float fontSpacing, float lineSpacing)
// {
//     int len = TextLength(text);
//     int tempLen = 0;                // Used to count longer text line num chars
//     int lenCounter = 0;

//     float tempTextWidth = 0.0f;     // Used to count longer text line width

//     float scale = fontSize/(float)font.baseSize;
//     float textHeight = scale;
//     float textWidth = 0.0f;

//     int letter = 0;                 // Current character
//     int index = 0;                  // Index position in sprite font

//     for (int i = 0; i < len; i++)
//     {
//         lenCounter++;

//         int next = 0;
//         letter = GetCodepoint(&text[i], &next);
//         index = GetGlyphIndex(font, letter);

//         // NOTE: normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
//         // but we need to draw all of the bad bytes using the '?' symbol so to not skip any we set next = 1
//         if (letter == 0x3f) next = 1;
//         i += next - 1;

//         if (letter != '\n')
//         {
//             if (font.glyphs[index].advanceX != 0) textWidth += (font.glyphs[index].advanceX+fontSpacing)/(float)font.baseSize*scale;
//             else textWidth += (font.recs[index].width + font.glyphs[index].offsetX)/(float)font.baseSize*scale;
//         }
//         else
//         {
//             if (tempTextWidth < textWidth) tempTextWidth = textWidth;
//             lenCounter = 0;
//             textWidth = 0.0f;
//             textHeight += scale + lineSpacing/(float)font.baseSize*scale;
//         }

//         if (tempLen < lenCounter) tempLen = lenCounter;
//     }

//     if (tempTextWidth < textWidth) tempTextWidth = textWidth;

//     Vector3 vec = { 0 };
//     vec.x = tempTextWidth + (float)((tempLen - 1)*fontSpacing/(float)font.baseSize*scale); // Adds chars spacing to measure
//     vec.y = 0.25f;
//     vec.z = textHeight;

//     return vec;
// }
