/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** handle_button_interaction
*/

#include "my_rpg.h"

void update_slider(slider_t *slider, int mouse_pos)
{
    const char file[] = "assets/hud/buttons.png";
    sfIntRect texture_rect;
    sfTexture *texture;
    sfVector2f size;

    texture_rect.left   = 0;
    texture_rect.top    = slider->random_texture * slider->pos_size.height;
    texture_rect.width  = mouse_pos - slider->pos_size.left;
    texture_rect.height = slider->pos_size.height;
    size = (sfVector2f){texture_rect.width, texture_rect.height};
    texture = sfTexture_createFromFile(file, &texture_rect);
    sfRectangleShape_setSize(slider->slide, size);
    sfRectangleShape_setTexture(slider->slide, texture, sfTrue);
}

void update_button(button_t *button, sfVector2f *state)
{
    sfRectangleShape_setScale(button->rect, *state);
    sfText_setScale(button->text, *state);
}
