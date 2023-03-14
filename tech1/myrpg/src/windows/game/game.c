/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** game
*/

#include "my_rpg.h"

static size_t handle_game_keys( sfRenderWindow **win,   \
                                sfEvent *event,         \
                                game_t *game)
{
    size_t return_code;

    return_code = (event->key.code == sfKeyEscape ? pause_loop(win)           \
    :             (event->key.code == sfKeyO      ? toggle_overlay(game)      \
    :             (event->key.code == sfKeyH      ? toggle_hud(game)          \
    :             (event->key.code == sfKeyI      ? inventory_loop(win, game) \
    : 1))));
    return (return_code);
}

static void handle_game_events( game_t *game,            \
                                sfRenderWindow **win,    \
                                sfEvent *event,          \
                                int *check_return)
{
    switch (event->type) {
        case (sfEvtClosed):
            sfRenderWindow_close(*win);
            break;
        case (sfEvtKeyPressed):
            (*check_return) = handle_game_keys(win, event, game);
            break;
        default:
            break;
    }
}

int game_loop(sfRenderWindow **win, bool *game_mode)
{
    int check_return = 1;
    sfEvent event;
    game_t game;

    if (init_game(win, &game, game_mode)) return (84);
    WAIT_FOR_BUTTON_RELEASE;
    while (check_return && sfRenderWindow_isOpen(*win)) {
        while (sfRenderWindow_pollEvent(*win, &event))
            handle_game_events(&game, win, &event, &check_return);
        sfRenderWindow_clear(*win, sfBlack);
        if (handle_game(win, &game, &event))
            check_return = 84;
        sfRenderWindow_display(*win);
    }
    create_map_file(&game);
    create_feature(&game);
    destroy_game(&game);
    sfRenderWindow_setMouseCursorVisible(*win, true);
    return ((check_return == 84 ? 84 : -1));
}
