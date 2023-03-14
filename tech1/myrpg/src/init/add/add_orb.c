/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** add_orb.c
*/

#include "my_rpg.h"

void add_orb(game_t *game)
{
    sfVector2f origin;
    sfTexture *text;
    if (game->map->stair == 0)
        return;
    game->player.orb.rect = sfCircleShape_create();
    game->player.orb.state++;
    game->player.orb.coord.left = (game->map->stair - 1) * 190;
    origin = (sfVector2f){85, 85};
    text = sfTexture_createFromFile("assets/particles/orb.png",
                                    &game->player.orb.coord);
    game->player.orb.speed += 0.7;
    sfCircleShape_setOrigin(game->player.orb.rect, origin);
    sfCircleShape_setRadius(game->player.orb.rect, 85);
    sfCircleShape_setTexture(game->player.orb.rect, text, sfTrue);
}
