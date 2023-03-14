/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** handle_inventory
*/

#include <stdlib.h>
#include "my_rpg.h"

static bool add_icon(   sfRectangleShape ****rect,   \
                        sfFloatRect pos_size,        \
                        char **paths,                \
                        cell_t cell)
{
    sfRectangleShape *temp;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f pos;

    if (cell.i > 7) return (0);
    texture = sfTexture_createFromFile(paths[cell.i], NULL);
    pos = (sfVector2f){ pos_size.left - pos_size.height * 1.1, pos_size.top };
    size = (sfVector2f){ pos_size.height, pos_size.height };
    if (!(temp = create_rectangle(pos, size, texture)))
        return (1);
    (*rect)[cell.i][0] = temp;
    return (0);
}

static bool add_square( sfRectangleShape ****rect,  \
                        sfFloatRect pos_size,       \
                        cell_t cell)
{
    sfRectangleShape *temp;
    sfVector2f size;
    sfVector2f pos;

    pos = (sfVector2f){ pos_size.left, pos_size.top };
    size = (sfVector2f){ 23, pos_size.height };
    if (!(temp = create_rectangle(pos, size, NULL)))
        return (1);
    sfRectangleShape_setFillColor(temp, sfWhite);
    sfRectangleShape_setOutlineThickness(temp, 1.0f);
    sfRectangleShape_setOutlineColor(temp, sfBlack);
    (*rect)[cell.i][cell.j] = temp;
    return (0);
}

static bool add_plus(   sfRectangleShape ****rect,  \
                        sfFloatRect pos_size,       \
                        cell_t cell)
{
    sfRectangleShape *temp;
    sfTexture *texture;
    sfVector2f size;
    sfVector2f pos;

    texture = sfTexture_createFromFile("assets/hud/plus.png", NULL);
    pos = (sfVector2f){ pos_size.left, pos_size.top };
    size = (sfVector2f){ pos_size.height, pos_size.height };
    if (!(temp = create_rectangle(pos, size, texture)))
        return (1);
    sfRectangleShape_setFillColor(temp, (sfColor){0, 255, 0, 0});
    if (!temp)
        return (1);
    (*rect)[cell.i][11] = temp;
    return (0);
}

bool create_inventory_stat( char **paths,       \
                            cell_t cell,        \
                            sfRectangleShape ****rect,      \
                            sfFloatRect pos_size)
{
    int return_code = 0;

    switch (cell.j) {
        case 0:
            return_code = add_icon(rect, pos_size, paths, cell);
            break;
        case 11:
            return_code = add_plus(rect, pos_size, cell);
            break;
        default:
            return_code = add_square(rect, pos_size, cell);
            break;
    }
    return (return_code);
}

bool create_inventory_list( sfRectangleShape ****rect,       \
                            size_t count,        \
                            char **paths,        \
                            sfFloatRect pos_size)
{
    sfColor color;
    cell_t cell;
    bool n;

    color = (sfColor){158, 110, 110, 255};
    (*rect) = malloc(sizeof(sfRectangleShape **) * 8);
    if (!(*rect)) return (1);
    pos_size.top += 28;
    pos_size.left = WIDTH / 2 - 800 / 2 + 50;
    for (int i = 0; i < 8; i++) {
        (*rect)[i] = malloc(sizeof(sfRectangleShape *) * count);
        for (int j = 0; j < 12; j++) {
            cell = (cell_t){ 0, i, j };
            create_inventory_stat(paths, cell, rect, pos_size);
            pos_size.left += 30;
        }
        pos_size.left = WIDTH / 2 - 800 / 2 + 50;
        pos_size.top += 58;
    }
    return (0);
}
