/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** destroy_game
*/

#include "my_rpg.h"
#include "queue.h"

void destroy_game(game_t *game)
{
    destroy_player(&game->player);
    destroy_map(&game->map);
    destroy_hud(&game->hud);
    q_destroy(game->bullets);
    if (game->entity_movement)
        sfClock_destroy(game->entity_movement);
    if (game->bullet_delay)
        sfClock_destroy(game->bullet_delay);
}
