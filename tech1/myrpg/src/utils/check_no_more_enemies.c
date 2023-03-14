/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** check_no_more_enemies
*/

#include "my_rpg.h"

void check_no_more_enemies(game_t *game)
{
    game->state.enemies_left = true;

    if (!game->enem) return;
    for (entity_t *iter = game->enem->head; iter; iter = iter->next) {
        game->state.enemies_left = (!iter->dead ? true : false);
        if (game->state.enemies_left)
            break;
    }
}
