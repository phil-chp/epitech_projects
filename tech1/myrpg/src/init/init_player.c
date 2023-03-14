/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** init_player
*/

#include "my_rpg.h"

static void handle_stats_and_items(entity_t *pl, int **stats)
{
    pl->pos           = (sfVector2f){ WIDTH / 2, HEIGHT / 2 };
    pl->size          = (sfVector2f){ 96.0, 96.0 };
    pl->scale         = (sfVector2f){ 1, 1 };
    pl->stats.health  = (*stats)[0];
    pl->stats.mana    = (*stats)[1];
    pl->stats.stars   = (*stats)[2];
    pl->stats.keys    = (*stats)[3];
    pl->stats.bombs   = (*stats)[4];
    pl->stats.speed   = (*stats)[5];
    pl->stats.arms    = (*stats)[6];
    pl->stats.defense = (*stats)[7];
    pl->stats.jump    = (*stats)[8];
    pl->stats.attack  = (*stats)[9];
    pl->stats.special = (*stats)[10];
}

static int handle_body(entity_t *pl)
{
    sfTexture *texture;
    sfVector2f origin;

    texture = sfTexture_createFromFile("assets/entities/player.png", NULL);
    pl->body = create_rectangle(pl->pos, pl->size, texture);
    if (!pl->body || !texture)
        return (1);
    sfRectangleShape_setTextureRect(pl->body, (sfIntRect) {0, 64 * 2, 64, 64});
    sfRectangleShape_setScale(pl->body, pl->scale);
    origin = (sfVector2f){ pl->size.x / 2, pl->size.y / 2 };
    sfRectangleShape_setOrigin(pl->body, origin);
    return (0);
}

bool init_player(entity_t *pl, int **stats)
{
    handle_stats_and_items(pl, stats);
    if (handle_body(pl))
        return (1);
    pl->animation = sfClock_create();
    if (!pl->animation)
        return (1);
    return (0);
}
