/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_sliders
*/

#include <stdlib.h>
#include "my_rpg.h"

bool create_slider(  slider_t *slider,        \
                    char *string,            \
                    sfFloatRect pos_size,    \
                    sfTexture *texture)
{
    sfVector2f size = {pos_size.width, pos_size.height};
    sfVector2f pos  = {pos_size.left,  pos_size.top};
    sfColor darker  = { 200, 0, 10, 255 };
    sfVector2f text_pos;
    size_t char_size;

    slider->pos_size = pos_size;
    if (!(slider->rect = create_rectangle(pos, size, texture)))
        return (1);
    if (!(slider->slide = create_rectangle(pos, size, texture)))
        return (1);
    sfRectangleShape_setFillColor(slider->rect, darker);
    char_size = 50;
    text_pos = calculate_text_position(string, pos, size, char_size);
    slider->text = create_text(string, text_pos, sfBlack, char_size);
    if (!slider->text)
        return (1);
    return (0);
}

static bool create_inventory_slider(slider_t *slider,        \
                                    char *string,            \
                                    sfFloatRect pos_size,    \
                                    size_t char_size)
{
    sfVector2f size = {pos_size.width, pos_size.height};
    sfVector2f pos  = {pos_size.left,  pos_size.top};
    sfColor darker  = { 200, 0, 10, 255 };
    sfVector2f text_pos;

    slider->pos_size = pos_size;
    if (!(slider->rect = create_rectangle(pos, size, NULL)))
        return (1);
    if (!(slider->slide = create_rectangle(pos, size, NULL)))
        return (1);
    sfRectangleShape_setFillColor(slider->rect, darker);
    text_pos = calculate_text_position(string, pos, size, char_size);
    slider->text = create_text(string, text_pos, sfBlack, char_size);
    if (!slider->text)
        return (1);
    return (0);
}

bool create_slider_list(slider_t **sliders, \
                        size_t count,       \
                        char **texts,       \
                        sfFloatRect pos_size)
{
    char path[] = "assets/hud/buttons.png";
    sfTexture **textures;

    (*sliders) = malloc(sizeof(slider_t) * count);
    if (!(*sliders))
        return (1);
    if (!(textures = get_textures_for_buttons(path, 2)))
        return (1);
    for (size_t i = 0; i < count; i++) {
        size_t rand = get_random(0, 1);
        (*sliders)[i].random_texture = rand;
        size_t n;
        n = create_slider(&(*sliders)[i], texts[i], pos_size, textures[rand]);
        if (n) return (1);
        pos_size.top += 130;
    }
    return (0);
}
