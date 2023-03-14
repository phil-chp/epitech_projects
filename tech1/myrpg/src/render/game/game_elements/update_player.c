/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_player
*/

#include "my_rpg.h"

void update_orb(sfRenderWindow **win, entity_t *pl)
{
    if (pl->orb.state == 0)
        return;
    sfCircleShape_setPosition(pl->orb.rect, (sfVector2f){pl->pos.x, pl->pos.y});
    sfCircleShape_rotate(pl->orb.rect, pl->orb.speed);
    sfRenderWindow_drawCircleShape(*win, pl->orb.rect, NULL);
}

void update_player(sfRenderWindow **win, entity_t *pl)
{
    if (get_time_elapsed(pl->animation, 10000) > 500 / pl->stats.speed) {
        handle_animation(&pl);
        sfClock_restart(pl->animation);
    }
    sfRenderWindow_drawRectangleShape(*win, pl->body, NULL);
    update_orb(win, pl);
}
