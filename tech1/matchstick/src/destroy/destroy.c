/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** free_map
*/

#include <stdlib.h>
#include "matchstick.h"

void destroy(game_t *game)
{
    for (int i = 0; game->map[i]; i++)
        if (game->map[i]) free(game->map[i]);
    if (game->counts) free(game->counts);
    if (game->map) free(game->map);
    if (game) free(game);
}
