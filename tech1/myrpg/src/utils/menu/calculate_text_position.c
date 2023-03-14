/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** calculate_text_position
*/

#include <SFML/Graphics.h>
#include "my.h"

sfVector2f calculate_text_position( char *string,       \
                                    sfVector2f pos,     \
                                    sfVector2f size,    \
                                    size_t char_size)
{
    sfVector2f text_pos;
    int text_len;

    text_len = my_strlen(string);
    text_pos.x = pos.x + (size.x / 2) - ((text_len * char_size) / 4);
    text_pos.y = pos.y + (size.y / 2) - char_size / 1.5;
    return (text_pos);
}
