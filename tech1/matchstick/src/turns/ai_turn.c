/*
** EPITECH PROJECT, 2021
** matchstick (Workspace)
** File description:
** ai_turn
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static void get_random_line(game_t *game, int *rline, int *rmatch, int matches)
{
    while (*rmatch < 1 && matches != 0) {
        *rline = rand() % (game->h + 1);
        if (*rline > 0)
            *rmatch = game->counts[*rline - 1];
    }
}

static void ai_big_brain(game_t *game, int *line, int *match)
{
    int rmatch = 0;
    int rline;

    int matches = total_matches_left(game);
    get_random_line(game, &rline, &rmatch, matches);
    *line = rline;
    if (matches > 4) {
        if (rmatch > game->max)
            *match = game->max;
        else
            *match = rmatch;
    } else {
        if (rmatch < matches)
            *match = rmatch;
        else if (rmatch - 1 > 0)
            *match = rmatch - 1;
        else
            *match = rmatch;
    }
}

int ai_turn(game_t *game)
{
    int line = -1, match = -1;

    my_lprintf("\nAI's turn...\n", game->map);
    ai_big_brain(game, &line, &match);
    update_map(game, line, match);
    my_lprintf("AI removed %d match(es) from line %d\n%t",        \
                                            match, line, game->map);
    return (0);
}
