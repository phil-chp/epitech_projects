/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_obj.c
*/

#include "my_rpg.h"

static void handle_enemy_deco_coll(entity_t **enemy, sfFloatRect area)
{
    entity_t *iter = NULL;

    for (iter = (*enemy)->head; iter; iter = iter->next)
        handle_decoration_collision(&iter->pos, area);
}

void update_obj(sfRenderWindow **win, game_t *game)
{
    obj_t *iter = NULL;
    sfFloatRect area;
    sfVector2f pos, size;

    if (!game->obj)
        return;
    for (iter = game->obj->head; iter; iter = iter->next) {
        area = sfRectangleShape_getGlobalBounds(iter->rect);
        if (iter->wall) {
            if (game->enem && game->enem->head)
                handle_enemy_deco_coll(&game->enem, area);
            handle_decoration_collision(&game->player.pos, area);
        }
        size = sfRectangleShape_getSize(iter->rect);
        pos = sfRectangleShape_getPosition(iter->rect);
        if (iter->stars || iter->trap)
            handle_obj_collision(&iter, game, pos, size);
        if (iter->draw)
            sfRenderWindow_drawRectangleShape(*win, iter->rect, NULL);
    }
}
