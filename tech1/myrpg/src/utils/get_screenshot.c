/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_screenshot
*/

#include "my_rpg.h"

int get_screenshot(sfSprite **screenshot, sfRenderWindow *win)
{
    unsigned int u_zero = 0;
    sfTexture *ss_texture;
    sfVector2u size;

    if (!((*screenshot) = sfSprite_create()))
        return (1);
    size = sfRenderWindow_getSize(win);
    if (!(ss_texture = sfTexture_create(size.x, size.y)))
        return (1);
    sfTexture_updateFromRenderWindow(ss_texture, win, u_zero, u_zero);
    sfSprite_setTexture(*screenshot, ss_texture, sfTrue);
    sfSprite_setColor(*screenshot, (sfColor){255, 255, 255, 75});
    return (0);
}
