/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** init_game
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "matchstick.h"
#include "my.h"

static int *gen_counts(int h)
{
    int *counts;
    int j;

    j = 1;
    counts = malloc(sizeof(int) * h);
    if (!counts)
        return (NULL);
    for (int i = 0; i < h; i++, j += 2)
        counts[i] = j;
    return (counts);
}

game_t *init_game(char *h, char *max)
{
    game_t *game;

    game = malloc(sizeof(game_t));
    if (!game) {
        write(2, "matchstick: Ran out of memory\n", 31);
        return (NULL);
    }
    game->h = my_getnbr(h);
    if ((game->counts = gen_counts(game->h)) == NULL) {
        write(2, "matchstick: Ran out of memory\n", 31);
        if (game) free(game);
        return (NULL);
    }
    game->max = my_getnbr(max);
    srandom(time(NULL));
    return (game);
}
