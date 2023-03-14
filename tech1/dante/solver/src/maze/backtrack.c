/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** backtrack
*/

#include <stdlib.h>
#include "solver.h"
#include "stack.h"

void backtrack(sol_t *sol, node_t *node)
{
    while (node && node->parent) {
        int x = node->pos.x;
        int y = node->pos.y;

        sol->map[x][y] = PASS;
        node = node->parent;
    }
}
