/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** add_enem.c
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

static bool add_entity(entity_t **entity,       \
                        sfFloatRect pos_size,   \
                        char *path,             \
                        cell_t *cell)
{
    sfIntRect rect = { 0, 0, 64, 64};
    sfTexture *text = NULL;
    sfVector2u text_size;
    sfVector2f origin;

    (*entity)->pos = (sfVector2f){pos_size.left, pos_size.top};
    (*entity)->size = (sfVector2f){pos_size.width, pos_size.height};
    origin = (sfVector2f){ (*entity)->size.x / 2, (*entity)->size.y / 2 };
    if (path) text = sfTexture_createFromFile(path, NULL);
    (*entity)->body = create_rectangle((*entity)->pos, (*entity)->size, text);
    if (!((*entity)->body) || handle_health_bar(entity)) return (1);
    if (text) {
        rect.top = (int) sfTexture_getSize(text).y - rect.height;
        sfRectangleShape_setTextureRect((*entity)->body, rect);
    } else
        sfRectangleShape_setFillColor((*entity)->body, sfBlue);
    (*entity)->cell = (cell_t)(*cell);
    sfRectangleShape_setOrigin((*entity)->body, origin);
    if (!((*entity)->animation = sfClock_create())) return (1);
    return (0);
}

void enemy_stat_manager(game_t *game, entity_t **temp, char c)
{
    int stair = game->map->stair;

    (*temp)->stats.speed = 20 * get_random(1, (stair + 4));
    (*temp)->stats.health = stair * 10;
    (*temp)->stats.attack = 5 * stair;
    (*temp)->stats.special = (c == 'B' ? 1 * (stair + 1) : 0);
    (*temp)->dead = false;
}

static void get_ennemies_path(char *(*path)[18])
{
    (*path)[0]  = my_strdup("assets/entities/boss_1.png");
    (*path)[1]  = my_strdup("assets/entities/boss_2.png");
    (*path)[2]  = my_strdup("assets/entities/boss_3.png");
    (*path)[3]  = my_strdup("assets/entities/boss_4.png");
    (*path)[4]  = my_strdup("assets/entities/boss_5.png");
    (*path)[5]  = my_strdup("assets/entities/spider_1.png");
    (*path)[6]  = my_strdup("assets/entities/spider_2.png");
    (*path)[7]  = my_strdup("assets/entities/spider_3.png");
    (*path)[8]  = my_strdup("assets/entities/pouple.png");
    (*path)[9]  = my_strdup("assets/entities/not_a_pokemon_1.png");
    (*path)[10] = my_strdup("assets/entities/not_a_pokemon_2.png");
    (*path)[11] = my_strdup("assets/entities/not_a_pokemon_3.png");
    (*path)[12] = my_strdup("assets/entities/not_a_pokemon_4.png");
    (*path)[13] = my_strdup("assets/entities/skeleton_1.png");
    (*path)[14] = my_strdup("assets/entities/skeleton_2.png");
    (*path)[15] = my_strdup("assets/entities/skeleton_3.png");
    (*path)[16] = my_strdup("assets/entities/skeleton_4.png");
    (*path)[17] = my_strdup("assets/entities/enemy.png");
}

static bool handle_entity_type(game_t *game, cell_t *cell, entity_t **temp)
{
    char *enemies[18];
    char *path = NULL;
    sfFloatRect pos_size = {(cell->j - 1) * 64 + 320, \
                            (cell->i - 1) * 64 + 188, \
                            64, 64 };

    get_ennemies_path(&enemies);
    if (cell->c == 'B') {
        pos_size.width = 256;
        pos_size.height = 320;
        path = my_strdup(enemies[game->map->stair]);
    } else {
        pos_size.width = 96;
        pos_size.height = 96;
        path = my_strdup(enemies[get_random(5, 17)]);
    }
    enemy_stat_manager(game, temp, cell->c);
    if (add_entity(temp, pos_size, path, cell)) return (1);
    free(path);
    return (0);
}

bool enemy_manager(game_t *game, cell_t *cell)
{
    entity_t *temp, *iter;

    if (!(temp = malloc(sizeof(entity_t)))) return (NULL);
    if (handle_entity_type(game, cell, &temp)) return (1);
    if (!(temp)) return (1);
    if (game->enem == NULL) {
        game->enem = temp;
        game->enem->next = NULL;
        game->enem->head = temp;
        game->enem->prev = NULL;
    } else {
        for (iter = game->enem->head; iter->next; iter = iter->next);
        temp->next = NULL;
        temp->head = game->enem->head;
        temp->prev = iter;
        iter->next = temp;
    }
    return (0);
}
