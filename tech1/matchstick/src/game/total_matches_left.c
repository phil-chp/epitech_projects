/*
** EPITECH PROJECT, 2021
** matchstick (Workspace)
** File description:
** total_matches_left
*/

#include "matchstick.h"

int total_matches_left(game_t *game)
{
    int m = 0;

    for (int i = 0; i < game->h; i++)
        m += game->counts[i];
    return (m);
}
