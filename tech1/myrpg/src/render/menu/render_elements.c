/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** elements
*/

#include "my_rpg.h"

void render_elements(sfRenderWindow **win, menu_t *menu)
{
    sfRenderWindow_drawSprite(*win, menu->bg, NULL);
}
