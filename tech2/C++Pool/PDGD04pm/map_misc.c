/*
** EPITECH PROJECT, 2022
** PDG-D4-PM (Workspace)
** File description:
** map_misc
*/

#include <stddef.h>
#include <stdlib.h>
#include "map.h"

unsigned int map_get_size(map_t map)
{
    return (list_get_size(map));
}

bool map_is_empty(map_t map)
{
    return (list_is_empty(map));
}

void map_clear(map_t *map_ptr)
{
    node_t *temp = *map_ptr;

    while (temp) {
        *map_ptr = (*map_ptr)->next;
        if (temp->value) free(temp->value);
        temp->value = NULL;
        free(temp);
        temp = *map_ptr;
    }
    *map_ptr = NULL;
}
