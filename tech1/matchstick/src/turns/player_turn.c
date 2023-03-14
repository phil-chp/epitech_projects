/*
** EPITECH PROJECT, 2021
** matchstick (Workspace)
** File description:
** player_turn
*/

#include <stdio.h>
#include "matchstick.h"
#include "my.h"

static void get_line_error_handling(game_t *game, int line)
{
    if (line < 0) {
        my_lprintf("%s\n", "Error: invalid input (positive number expected)");
    } else if (line < 1 || line > game->h) {
        my_lprintf("%s\n", "Error: this line is out of range");
    } else {
        if (game->counts[line - 1] == 0) {
            my_lprintf("%s\n", "Error: no more matches on this line");
        }
    }
}

static void get_match_error_handling(game_t *game, int line, int match)
{
    if (match < 0)
        my_lprintf("%s\n", "Error: invalid input (positive number expected)");
    else if (match < 1) {
        my_lprintf("%s\n", "Error: you have to remove at least one match");
    } else {
        if (match > game->max) {
            my_lprintf("%s %d %s\n", "Error: you cannot remove more than",   \
                                            game->max, "matches per turn");
        } else if (match > game->counts[line - 1]) {
            my_lprintf("%s\n", "Error: not enough matches on this line");
        }
    }
}

static int get_line(game_t *game)
{
    char *line  = NULL;
    size_t size = 0;
    int li = 0;

    while (42) {
        my_lprintf("Line: ");
        if (getline(&line, &size, stdin) == EOF) return (EOF);
        li = my_getnbr(line);
        if (li > 0 && li <= game->h && game->counts[li - 1] != 0)
            break;
        get_line_error_handling(game, li);
    }
    return (li);
}

static int get_match(game_t *game, int l)
{
    char *line  = NULL;
    size_t size = 0;
    int m = 0;

    while (42) {
        my_lprintf("Matches: ");
        if (getline(&line, &size, stdin) == EOF) return (EOF);
        m = my_getnbr(line);
        if (m > 0 && m <= game->max && m <= game->counts[l - 1])
            break;
        get_match_error_handling(game, l, m);
        return (0);
    }
    return (m);
}

int player_turn(game_t *game)
{
    int match = 0, line = 0;

    my_lprintf("\nYour turn:\n");
    while (match == 0) {
        if ((line = get_line(game)) == EOF)
            return (EOF);
        if ((match = get_match(game, line)) == EOF)
            return (EOF);
    }
    update_map(game, line, match);
    my_lprintf("Player removed %d match(es) from line %d\n%t",        \
                                            match, line, game->map);
    return (0);
}
