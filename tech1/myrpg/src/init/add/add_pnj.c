/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** add_pnj.c
*/

#include "my_rpg.h"

bool pnj_manager(game_t *game, cell_t *cell)
{
    sfTexture *texture;

    game->pnj.size = (sfVector2f){ 64, 64 };
    game->pnj.pos = (sfVector2f){ (cell->j - 1) * 64 + 320, \
    (cell->i - 1) * 64 + 188 };
    texture = sfTexture_createFromFile("assets/entities/npc/npc.png", NULL);
    game->pnj.body = create_rectangle(game->pnj.pos, game->pnj.size, texture);
    if (!game->pnj.body) return (1);
    sfRectangleShape_setOrigin(game->pnj.body, \
    (sfVector2f) { game->pnj.size.x / 2, game->pnj.size.y / 2 });
    if (!texture)
        sfRectangleShape_setFillColor(game->pnj.body, sfRed);
    if (create_pop_up(&game->pnj.pop_up, game->pnj.pos, \
    game->map->stair)) return (1);
    return (0);
}
