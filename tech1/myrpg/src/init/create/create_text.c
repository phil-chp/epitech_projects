/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_text
*/

#include <SFML/Graphics.h>

sfText *create_text(char *string,           \
                    sfVector2f pos,         \
                    sfColor color,          \
                    unsigned int char_size)
{
    char *path = "assets/fonts/Carnevalee Freakshow.ttf";
    sfFont *font;
    sfText *text;

    if (!(font = sfFont_createFromFile(path)))
        return (NULL);
    if (!(text = sfText_create()))
        return (NULL);
    if (string) sfText_setString(text, string);
    if (pos.x > -1) sfText_setPosition(text, pos);
    if (color.a > 0) sfText_setColor(text, color);
    sfText_setCharacterSize(text, char_size);
    sfText_setFont(text, font);
    return (text);
}
