/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_overlay.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my_rpg.h"

static bool create_square(  overlay_t **temp,
                            sfVector2f size,
                            sfColor color,
                            cell_t cell)
{
    sfVector2f pos;

    pos.x = cell.j * size.x + 320;
    pos.y = cell.i * size.y + 188;
    if (!((*temp) = malloc(sizeof(overlay_t))))
        return (1);
    (*temp)->rect = sfRectangleShape_create();
    sfRectangleShape_setSize((*temp)->rect, size);
    sfRectangleShape_setPosition((*temp)->rect, pos);
    sfRectangleShape_setFillColor((*temp)->rect, color);
    return (0);
}

static bool overlay_manager(overlay_t **overlay,    \
                            overlay_t **iter,       \
                            overlay_t **temp)
{
    if (!((*temp)))
        return (1);
    if ((*overlay) == NULL) {
        (*overlay) = (*temp);
        (*overlay)->next = NULL;
        (*overlay)->head = (*temp);
    } else {
        for (*iter = (*overlay)->head; (*iter)->next; (*iter) = (*iter)->next);
        (*temp)->next = NULL;
        (*temp)->head = (*overlay)->head;
        (*iter)->next = (*temp);
    }
    return (0);
}

static void add_final_square(   overlay_t **overlay,
                                overlay_t **iter,
                                overlay_t **temp)
{
    for ((*iter) = (*overlay)->head; (*iter)->next; (*iter) = (*iter)->next);
    (*temp)->next = NULL;
    (*temp)->head = (*overlay)->head;
    (*iter)->next = (*temp);
}

bool create_overlay(overlay_t **overlay)
{
    sfVector2f size = { 64, 64 };
    overlay_t *iter, *temp;
    sfColor color;
    int count = 0;
    cell_t cell;

    (*overlay) = NULL;
    for (int i = 0; i < 11; i++) {
        count = (i % 2 == 0 ? 1 : 0);
        for (int j = 0; j < 20; j++) {
            cell = (cell_t){ cell.c, i, j };
            color = (count++ % 2 ? (sfColor){0, 255, 0, 50} \
                                :  (sfColor){0, 0, 255, 50});
            create_square(&temp, size, color, cell);
            overlay_manager(overlay, &iter, &temp);
        }
    }
    create_square(&temp, size, color, cell);
    add_final_square(overlay, &iter, &temp);
    return (0);
}

void update_overlay(sfRenderWindow **win, overlay_t **over, game_t *game)
{
    overlay_t *iter;

    if (game->state.overlay == true)
        for (iter = (*over)->head; iter->next; iter = iter->next)
            sfRenderWindow_drawRectangleShape(*win, iter->rect, NULL);
}
