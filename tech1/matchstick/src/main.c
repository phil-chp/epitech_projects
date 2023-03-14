/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** main
*/

#include <stdio.h>
#include "matchstick.h"
#include "my.h"

static int game_loop(game_t *game)
{
    int return_code = 0;

    my_lprintf("%t", game->map);
    for (int turn = 0; return_code == 0; turn++) {
        if (turn % 2 == 0) {
            if (player_turn(game) == EOF) return (0);
        } else {
            if (ai_turn(game) == 84) return (84);
        }
        return_code = check_win(game, turn % 2);
    }
    print_win(return_code);
    return (return_code);
}

int main(int ac, char **av)
{
    int return_code = 0;
    game_t *game;

    return_code = error_handling(ac, av);
    if (return_code == 0) {
        game = init_game(av[1], av[2]);
        game->map = create_map(game->h);
        return_code = game_loop(game);
        destroy(game);
    }
    return (return_code);
}
