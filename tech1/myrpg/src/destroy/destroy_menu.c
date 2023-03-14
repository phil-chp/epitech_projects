/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** menu
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_menu(menu_t *menu)
{
    if (menu->bg) sfSprite_destroy(menu->bg);
    if (menu->music) sfMusic_destroy(menu->music);
    for (size_t i = 0; i < menu->counts.x; i++) {
        sfRectangleShape *rect = menu->button[i].rect;
        if (menu->button[i].text) sfText_destroy(menu->button[i].text);
        if (rect) sfRectangleShape_destroy(rect);
    }
    if (menu->button) free(menu->button);
}
