/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** window
*/

#include "my_rpg.h"

int init_window(sfRenderWindow **win, char *name)
{
    sfVideoMode mode;

    mode = (sfVideoMode){ WIDTH, HEIGHT, PIXELS };
    *win = sfRenderWindow_create(mode, name, sfClose, NULL);
    if (!*win)
        return (1);
    sfRenderWindow_setFramerateLimit(*win, FPS);
    return (0);
}
