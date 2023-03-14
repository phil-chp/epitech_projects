/*
** EPITECH PROJECT, 2021
** matchstick (Workspace)
** File description:
** check_win
*/

#include "matchstick.h"

int check_win(game_t *game, int turn)
{
    if (total_matches_left(game) == 0)
        return (turn == 0 ? AI_W : PL_W);
    return (0);
}
