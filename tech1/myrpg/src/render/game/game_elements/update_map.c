/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_map
*/

#include <stdbool.h>
#include "my_rpg.h"

void update_map(sfRenderWindow **win, game_t *game)
{
    sfIntRect rect;

    rect = (sfIntRect){0, 0, 49, 33};
    for (size_t i = 0; i < 2; i++) {
        rect.left = (game->doors[i].is_open ? 0 : 49);
        sfRectangleShape_setTextureRect(game->doors[i].door, rect);
    }
    render_map(win, &game->map);
    sfRenderWindow_drawRectangleShape((*win), game->map->number, NULL);
    if (!game->doors[0].disabled)
        sfRenderWindow_drawRectangleShape((*win), game->doors[0].door, NULL);
    if (!game->doors[1].disabled)
        sfRenderWindow_drawRectangleShape((*win), game->doors[1].door, NULL);
    if (game->hole.state == true)
        sfRenderWindow_drawRectangleShape(*win, game->hole.rect, NULL);
}
