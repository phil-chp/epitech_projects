/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_minimap.c
*/

#include "my_rpg.h"

void handle_minimap(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->hud.minimap.sprite);
    pos.x += 7 + (game->map->room - 1) * 25.4;
    pos.y += 2 + game->map->stair * 26;
    sfCircleShape_setPosition(game->hud.minimap.circle, pos);
}
