/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_buttons
*/

#include <stdlib.h>
#include "my_rpg.h"

bool create_button( button_t *button,        \
                    char *string,           \
                    sfFloatRect pos_size,   \
                    sfTexture *texture)
{
    sfVector2f size = {pos_size.width, pos_size.height};
    sfVector2f pos = {pos_size.left, pos_size.top};
    sfVector2f text_pos;
    size_t char_size;

    button->pos_size = pos_size;
    if (!(button->rect = create_rectangle(pos, size, texture)))
        return (1);
    char_size = 50;
    text_pos = calculate_text_position(string, pos, size, char_size);
    button->text = create_text(string, text_pos, sfBlack, char_size);
    if (!button->text)
        return (1);
    return (0);
}

bool create_button_list(button_t **buttons,       \
                        size_t count,            \
                        char **texts,            \
                        sfFloatRect pos_size)
{
    char path[] = "assets/hud/buttons.png";
    sfTexture **textures;

    (*buttons) = malloc(sizeof(button_t) * count);
    if (!(*buttons))
        return (1);
    if (!(textures = get_textures_for_buttons(path, 2)))
        return (1);
    for (size_t i = 0; i < count; i++) {
        size_t rand = get_random(0, 1);
        size_t n;
        n = create_button(&(*buttons)[i], texts[i], pos_size, textures[rand]);
        if (n) return (1);
        pos_size.top += 130;
    }
    return (0);
}
