/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** get_neighbors
*/

#include <stdlib.h>
#include "generator.h"

int get_neighbors(gen_t *gen, cell_t *cell)
{
    cell_t neighbors[2];
    cell_t to_check[2];
    int n = 0;

    to_check[0] = (cell_t){ cell->x - 1, cell->y };
    to_check[1] = (cell_t){ cell->x, cell->y - 1 };
    for (int i = 0; i < 2; i++)
        if (to_check[i].x >= 0 && to_check[i].x <= gen->x   \
        &&  to_check[i].y >= 0 && to_check[i].y <= gen->y)
            neighbors[n++] = to_check[i];
    if (n > 0)
        (*cell) = neighbors[rand() % n];
    return (n);
}
