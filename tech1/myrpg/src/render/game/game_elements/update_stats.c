/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_stats.c
*/

#include "my_rpg.h"
#include "my.h"

void update_stats(game_t *game)
{
    sfVector2f size;

    size = sfRectangleShape_getSize(game->hud.health.rect);
    size.x = game->player.stats.health;
    sfRectangleShape_setSize(game->hud.health.rect, size);
    sfText_setString(game->hud.attack.text, \
                    my_getstr(game->player.stats.attack));
    sfText_setString(game->hud.defense.text, \
                    my_getstr(game->player.stats.defense));
    sfText_setString(game->hud.arms.text, my_getstr(game->player.stats.arms));
    sfText_setString(game->hud.special.text, \
                    my_getstr(game->player.stats.special));
    sfText_setString(game->hud.jump.text, my_getstr(game->player.stats.jump));
    sfText_setString(game->hud.stars.text, my_getstr(game->player.stats.stars));
    sfText_setString(game->hud.keys.text, my_getstr(game->player.stats.keys));
    sfText_setString(game->hud.bombs.text, my_getstr(game->player.stats.bombs));
    sfText_setString(game->hud.jump.text, my_getstr(game->player.stats.jump));
}
