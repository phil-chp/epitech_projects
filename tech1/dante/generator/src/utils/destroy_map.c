/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** destroy_map
*/

#include <stdlib.h>
#include "generator.h"

void destroy_map(gen_t *gen)
{
    for (int i = 0; gen->map[i]; i++)
        free(gen->map[i]);
    if (gen->map) free(gen->map);
}
