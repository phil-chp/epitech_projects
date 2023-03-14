/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** destroy_player
*/

#include "my_rpg.h"

void destroy_player(entity_t *pl)
{
    if (pl->body)
        sfRectangleShape_destroy(pl->body);
}
