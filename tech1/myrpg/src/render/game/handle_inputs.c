/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** handle_player
*/

#include "my_rpg.h"

sfVector2f handle_movement(int keys[4], float m)
{
    sfVector2f dir = { 0, 0 };

    (sfKeyboard_isKeyPressed(keys[0])           ? dir.x +=  0, dir.y += -m : 0);
    (sfKeyboard_isKeyPressed(keys[1]) && !dir.y ? dir.x +=  0, dir.y +=  m : 0);
    (sfKeyboard_isKeyPressed(keys[2])           ? dir.x += -m, dir.y +=  0 : 0);
    (sfKeyboard_isKeyPressed(keys[3]) && !dir.x ? dir.x +=  m, dir.y +=  0 : 0);
    return (dir);
}

void handle_inputs(entity_t *pl, sfMouseMoveEvent *mouse_move, sfUint64 s)
{
    sfIntRect rect = sfRectangleShape_getTextureRect(pl->body);
    sfVector2f decal = { 0, 0 };
    int keys[] = ZQSD_KEYS();
    sfVector2i mou;

    mou = (sfVector2i){ mouse_move->x, mouse_move->y };
    if ((mou.x >= 0 && mou.x <= WIDTH) && (mou.y >= 0 && mou.y <= HEIGHT)) {
        decal = handle_movement(keys, pl->stats.speed);
        normalize(&decal);
        rect.top =  (decal.x < 0 ? 64                   \
        :           (decal.x > 0 ? 64 * 3               \
        :           (!decal.x && decal.y < 0 ? 0        \
        :           (!decal.x && decal.y > 0 ? 64 * 2   \
        : 64 * 4))));
        rect.left = (rect.top == 64 * 4 ? 0 : rect.left);
        sfRectangleShape_setTextureRect(pl->body, rect);
        pl->pos = (sfVector2f){
            pl->pos.x + decal.x * s, pl->pos.y + decal.y * s
        };
        handle_collision(&pl->pos, GAME_FLOOR, (sfFloatRect){16, 16, 0, 32}, 1);
        sfRectangleShape_setPosition(pl->body, pl->pos);
    }
}
