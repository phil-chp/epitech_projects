/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** toggle.c
*/

#include "my_rpg.h"

int toggle_overlay(game_t *game)
{
    bool state;

    state = (game->state.overlay ? false : true);
    game->state.overlay = state;
    return (1);
}

int toggle_hud(game_t *game)
{
    bool state;

    state = (game->state.hud ? false : true);
    game->state.hud = state;
    return (1);
}
