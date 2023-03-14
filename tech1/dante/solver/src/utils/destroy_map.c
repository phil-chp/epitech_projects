/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** destroy_map
*/

#include <stdlib.h>
#include "solver.h"

void destroy_map(sol_t *sol)
{
    for (int i = 0; sol->map[i]; i++)
        free(sol->map[i]);
    if (sol->map) free(sol->map);
}
