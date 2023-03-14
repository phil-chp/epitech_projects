/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** init_settings_menu
*/

#include "my_rpg.h"

static void edit_button_data(menu_t *menu)
{
    char strings[] = "EXIT";
    sfVector2f button_pos;
    sfVector2f text_pos;
    sfVector2f size;

    size = (sfVector2f){600, 100};
    button_pos = (sfVector2f){660, 750};
    sfText_setString(menu->button[0].text, strings);
    text_pos = calculate_text_position(strings, button_pos, size, 50);
    sfRectangleShape_setPosition(menu->button[0].rect, button_pos);
    sfText_setPosition(menu->button[0].text, text_pos);
    button_pos.y -= 130;
}

int init_settings_menu(menu_t *menu, sfVector2f counts, char *music)
{
    if (init_menu(menu, counts, music))
        return (1);
    edit_button_data(menu);
    return (0);
}
