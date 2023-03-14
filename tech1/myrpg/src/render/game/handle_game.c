/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** handle_game
*/

#include "my_rpg.h"

void update_player_speed(sfRectangleShape **mana, entity_t *player)
{
    float x;

    x = sfRectangleShape_getSize(*mana).x;
    player->stats.speed = (x > 0 && (sfKeyboard_isKeyPressed(sfKeyLShift)  \
    || sfKeyboard_isKeyPressed(sfKeyRShift)) ? 1000 : 40);
}

int handle_game_second(sfRenderWindow **win, game_t *game, size_t elapsed)
{
    update_obj(win, game);
    handle_pop_up(&game->player, &game->pnj);
    update_enemy(win, game, &game->bullets);
    update_pnj(win, &game->pnj);
    update_player(win, &game->player);
    update_player_speed(&game->hud.mana.rect, &game->player);
    update_bar(game, elapsed);
    sfClock_restart(game->entity_movement);
    return (0);
}

static int check_end(game_t *game)
{
    sfFloatRect area;

    if (game->player.stats.health == 0)
        return (1);
    area = (sfFloatRect){ WIDTH / 2 - 25, HEIGHT / 2 - 25, 50, 50 };
    if (!game->map->right && !game->state.enemies_left  \
    && GET_COLLISION(game->player.pos, area))
        return (1);
    return (0);
}

int handle_game(sfRenderWindow **win, game_t *game, sfEvent *event)
{
    size_t elapsed = get_time_elapsed(game->entity_movement, 10000);
    size_t delay;

    if (check_end(game)) return (1);
    update_stats(game);
    handle_inputs(&game->player, &event->mouseMove, elapsed);
    update_map(win, game);
    if (handle_map(game)) return (1);
    update_overlay(win, &game->overlay, game);
    delay = get_time_elapsed(game->bullet_delay, 10000);
    if (delay > 40) {
        sfClock_restart(game->bullet_delay);
        if (handle_bullet(&game->bullets, &game->player, elapsed)) return (1);
    }
    if (game->bullets && !q_isempty(game->bullets))
        update_bullet(win, &game->bullets, elapsed);
    render_hud(win, &game->hud);
    if (handle_game_second(win, game, elapsed)) return (1);
    return (0);
}
