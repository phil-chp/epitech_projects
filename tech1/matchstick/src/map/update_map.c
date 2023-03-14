/*
** EPITECH PROJECT, 2021
** matchstick (Workspace)
** File description:
** update_map
*/

#include "matchstick.h"

void update_map(game_t *game, int line, int match)
{
    int w;

    w = game->h * 2;

    game->counts[line - 1] -= match;
    for (; w > 0 && match > 0; w--) {
        if (game->map[line][w] == '|') {
            game->map[line][w] = ' ';
            match--;
        }
    }
}
