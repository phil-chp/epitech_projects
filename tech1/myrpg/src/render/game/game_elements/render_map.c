/*
** EPITECH PROJECT, 2021
** $
** File description:
** render_map
*/

#include "my_rpg.h"

void render_map(sfRenderWindow **win, map_t **map)
{
    sfVector2f pos[] = {
        (sfVector2f){140, 7}, (sfVector2f){140, 540 * 2 - 7},
        (sfVector2f){960 * 2 - 140, 7}, (sfVector2f){960 * 2 - 140, 540 * 2 - 7}
    };
    sfVector2f scale[] = {
        (sfVector2f){3.46f, 3.46f}, (sfVector2f){3.46f, -3.46f},
        (sfVector2f){-3.46f, 3.46f}, (sfVector2f){-3.46f, -3.46f}
    };

    for (size_t i = 0; i < 4; i++) {
        sfRectangleShape_setPosition((*map)->back, pos[i]);
        sfRectangleShape_setScale((*map)->back, scale[i]);
        sfRenderWindow_drawRectangleShape((*win), (*map)->back, NULL);
    }
}
