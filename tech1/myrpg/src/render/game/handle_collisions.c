/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** handle_collisions
*/

#include "my_rpg.h"
#include "queue.h"

bool handle_bullet_collision(queue_man_t **bullets, sfVector2f enem_pos)
{
    sfFloatRect bounds;
    queue_t *temp;
    bullet_t *bl;
    int diff[2];
    int n = 0;

    temp = (*bullets)->rear;
    for (; temp; temp = temp->next) {
        bl = temp->obj;
        diff[0] = my_abs((int)bl->pos.x - enem_pos.x);
        diff[1] = my_abs((int)bl->pos.y - enem_pos.y);
        if (pythagoreas(diff[0], diff[1]) < 64.0) n++;
    }
    return (n > 0 ? 1 : 0);
}

void handle_collision(  sfVector2f *pos,            \
                        sfFloatRect game_floor,     \
                        sfFloatRect area,           \
                        bool check_doors)
{
    if (check_doors) {
        if ((pos->x < game_floor.left + area.left
        || pos->x > game_floor.width - area.top)
        && pos->y > 490 && pos->y < 560)
            return;
    }
    pos->x = (pos->x < game_floor.left + area.left \
    ? game_floor.left + area.left                  \
    : (pos->x > game_floor.width - area.top        \
    ? game_floor.width - area.top : pos->x));
    pos->y = (pos->y < game_floor.top + area.width \
    ? game_floor.top + area.width                  \
    : (pos->y > game_floor.height - area.height    \
    ? game_floor.height - area.height : pos->y));
}

void handle_decoration_collision(sfVector2f *pl_pos, sfFloatRect deco_area)
{
    sfVector2f pos;

    pos = *pl_pos;
    if (GET_COLLISION_CENTER(pos, deco_area)) {
        pos.x = (pos.x > deco_area.left - 20                  \
        && pos.x < deco_area.left                             \
        ? deco_area.left - 21 : (pos.x < deco_area.left + 84  \
        && pos.x > deco_area.left + deco_area.width           \
        ? deco_area.left + 85 : pos.x));
        pos.y = (pos.y > deco_area.top - 40                   \
        && pos.y < deco_area.top                              \
        ? deco_area.top - 41 : (pos.y < deco_area.top + 74    \
        && pos.y > deco_area.top + deco_area.height           \
        ? deco_area.top + 75 : pos.y));
        *pl_pos = pos;
    }

}

void handle_player_collision(entity_t *pl, sfVector2f pos, sfVector2f size)
{
    sfFloatRect enem;

    enem = (sfFloatRect){pos.x, pos.y, size.x, size.y};
    if (!GET_COLLISION_CENTER(pl->pos, enem))
        return;
    pl->stats.health -= 0.75f;
    // SON : Perte de vie.
}

void handle_obj_collision(  obj_t **iter, game_t *game, sfVector2f pos, \
                            sfVector2f size)
{
    sfFloatRect area;

    area = (sfFloatRect){pos.x, pos.y, size.x, size.y};
    if (!GET_COLLISION_CENTER(game->player.pos, area))
        return;
    if ((*iter)->stars) {
        game->player.stats.stars += 1;
        (*iter)->stars = false;
        (*iter)->draw = false;
        game->map->map[(*iter)->cell.i][(*iter)->cell.j] = ' ';
    } else {
        game->player.stats.health -= 0.5;
        (*iter)->stars = false;
    }
}
