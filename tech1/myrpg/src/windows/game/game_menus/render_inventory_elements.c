/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** render_inventory_elements.c
*/

#include <stdlib.h>
#include "my_rpg.h"

size_t *get_stats_in_order(stats_t *stats)
{
    size_t *stat;

    stat = malloc(sizeof(size_t) * 8);
    stat[0] = stats->health;
    stat[1] = stats->mana;
    stat[2] = stats->speed;
    stat[3] = stats->arms;
    stat[4] = stats->defense;
    stat[5] = stats->jump;
    stat[6] = stats->special;
    stat[7] = stats->attack;
    return (stat);
}

void fill_color_inv(size_t *stats, sfRectangleShape *rect, int j, int temp)
{
    sfColor color;

    if (j < 1 || j > 10)
        return;
    color = (temp >= 0 ? sfGreen : sfWhite);
    sfRectangleShape_setFillColor(rect, color);
}

void render_inventory_elements( sfRenderWindow **win, \
                                game_t *game,         \
                                inv_t *inv,           \
                                sfSprite **screenshot)
{
    size_t *stats;

    stats = get_stats_in_order(&game->player.stats);
    sfRenderWindow_drawSprite(*win, *screenshot, NULL);
    sfRenderWindow_drawSprite(*win, inv->background, NULL);
    for (size_t i = 0; i < 8; i++) {
        if (i < (long unsigned)game->map->stair)
            sfRenderWindow_drawCircleShape(*win, inv->orbs[i], NULL);
        int temp = stats[i];
        for (size_t j = 1; j < 12; j++, temp--) {
            fill_color_inv(stats, inv->rect[i][j], j, temp);
            sfRenderWindow_drawRectangleShape(*win, inv->rect[i][j], NULL);
        }
        sfRenderWindow_drawRectangleShape(*win, inv->rect[i][0], NULL);
    }
    sfRenderWindow_drawSprite(*win, inv->star, NULL);
    sfRenderWindow_drawText(*win, inv->star_count, NULL);
    if (stats) free(stats);
}
