/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** free_map.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "queue.h"

static void destroy_music(music_t *music)
{
    for (int i = 0; i < 14; i++) {
        free(music->path[i]);
        sfMusic_destroy(music->playlist[i].track);
    }
    if (music->playlist) free(music->playlist);
}

static void destroy_obj(obj_t **obj)
{
    obj_t *iter, *temp;

    for (iter = (*obj)->head; iter; ) {
        temp = iter;
        if (iter->rect)
            sfRectangleShape_destroy(iter->rect);
        iter = iter->next;
        free(temp);
    }
    (*obj) = NULL;
}

static void destroy_enem(entity_t **enem)
{
    entity_t *iter, *temp;

    for (iter = (*enem)->head; iter; ) {
        temp = iter;
        if (iter->body)
            sfRectangleShape_destroy(iter->body);
        iter = iter->next;
        free(temp);
    }
    (*enem) = NULL;
}

void destroy_features(game_t *game)
{
    game->map->map[0][1] = '#';
    if (game->map->room == 1 && game->map->stair != 0)
        game->hole.state = false;
    if (game->obj)
        destroy_obj(&game->obj);
    if (game->enem)
        destroy_enem(&game->enem);
    if (game->pnj.body) {
        sfRectangleShape_destroy(game->pnj.body);
        game->pnj.body = NULL;
    }
    q_flush(game->bullets);
}
