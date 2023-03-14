/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** handle_bullet
*/

#include <stdbool.h>
#include "my_rpg.h"
#include "queue.h"

static int check_shooting(int keys[4])
{
    return (sfKeyboard_isKeyPressed(keys[0]) \
    ||      sfKeyboard_isKeyPressed(keys[1]) \
    ||      sfKeyboard_isKeyPressed(keys[2]) \
    ||      sfKeyboard_isKeyPressed(keys[3]));
}

int handle_bullet(queue_man_t **bullets, entity_t *pl, sfUint64 s)
{
    int keys[] = ARROW_KEYS();
    sfVector2i temp;
    bullet_t *bl;

    if (check_shooting(keys) == 0) {
        pl->shooting = false;
        return (0);
    }
    pl->shooting = true;
    if (q_isempty(*bullets))
        if (!((*bullets) = q_initialize(0))) return (1);
    if (create_bullet(&bl)) return (1);
    bl->speed = handle_movement(keys, bl->motion);
    temp = (sfVector2i){(int)pl->pos.x, (int)pl->pos.y};
    bl->pos = (sfVector2f){
        pl->pos.x + bl->speed.x * s, pl->pos.y + bl->speed.y * s
    };
    sfCircleShape_setPosition(bl->body, bl->pos);
    if (q_enqueue(*bullets, bl)) return (1);
    return (0);
}
