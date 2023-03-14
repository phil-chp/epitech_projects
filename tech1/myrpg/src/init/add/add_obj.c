/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** add_obj.c
*/

#include <stdlib.h>
#include "my_rpg.h"

static bool set_texture(sfRectangleShape **shape, char *path, sfIntRect rect)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile(path, NULL);
    if (!texture) return (1);
    sfRectangleShape_setTexture(*shape, texture, sfFalse);
    if (rect.width != 0 && rect.height != 0)
        sfRectangleShape_setTextureRect(*shape, rect);
    return (0);
}

static bool obj_adder(cell_t *cell, obj_t **temp, sfIntRect rect)
{
    char *path[] = { "assets/elements/rocks.png", "assets/elements/traps.png", \
                    "assets/items/star.png" };

    (*temp)->stars = (cell->c == 'c' ? true : false);
    (*temp)->trap = (cell->c == 'T' ? true : false);
    (*temp)->draw = true;
    (*temp)->cell = (*cell);
    if (cell->c == 'R') {
        rect = (sfIntRect) {32 * (rand() % 3), 32 * (rand() % 3), 32, 32};
        if (set_texture(&(*temp)->rect, path[0], rect)) return (1);
    } else if (cell->c == 'T') {
        rect = (sfIntRect) {32 * (rand() % 2), 32 * (rand() % 2), 32, 32};
        if (set_texture(&(*temp)->rect, path[1], rect)) return (1);
    } else if (cell->c == 'c') {
        rect = (sfIntRect) {0, 0, 0, 0};
        if (set_texture(&(*temp)->rect, path[2], rect)) return (1);
    } else
        sfRectangleShape_setFillColor((*temp)->rect, sfWhite);
    return (0);
}

static bool add_obj(cell_t *cell, obj_t **temp)
{
    sfVector2f origin;
    sfVector2f size;
    sfVector2f pos;
    sfIntRect rect;

    size = (sfVector2f){64, 64};
    pos = (sfVector2f){
        (cell->j - 1) * 64 + 320 + size.x / 2,
        (cell->i - 1) * 64 + 188 + size.y / 2
    };
    if (obj_adder(cell, temp, rect))
        return (1);
    sfRectangleShape_setPosition((*temp)->rect, pos);
    sfRectangleShape_setSize((*temp)->rect, size);
    origin = (sfVector2f){size.x / 2, size.y / 2};
    sfRectangleShape_setOrigin((*temp)->rect, origin);
    return (0);
}

bool obj_manager(obj_t **obj, cell_t *cell)
{
    obj_t *temp, *iter;

    if (!(temp = malloc(sizeof(obj_t)))) return (1);
    if (!(temp->rect = sfRectangleShape_create())) return (1);
    if (add_obj(cell, &temp)) return (1);
    if (!(temp)) return (1);
        temp->wall = (cell->c == 'R' ? true : false);
    if ((*obj) == NULL) {
        (*obj) = temp;
        (*obj)->next = NULL;
        (*obj)->head = temp;
        (*obj)->prev = NULL;
    } else {
        for (iter = (*obj)->head; iter->next; iter = iter->next);
        temp->next = NULL;
        temp->head = (*obj)->head;
        temp->prev = iter;
        iter->next = temp;
    }
    return (0);
}
