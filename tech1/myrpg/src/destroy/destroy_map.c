/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** destroy_map
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_map(map_t **map)
{
    map_t *temp;
    map_t *rem;

    for (temp = (*map)->head; temp;) {
        for (size_t i = 0; temp->map[i]; i++)
            if (temp->map[i]) free(temp->map[i]);
        rem = temp;
        temp = temp->right;
        if (rem) free(rem);
    }
}
