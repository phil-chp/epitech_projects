/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_bullets
*/

#include "my_rpg.h"

void update_bullet( sfRenderWindow **win,   \
                    queue_man_t **bullets,  \
                    sfUint64 s)
{
    queue_t *temp;

    temp = (*bullets)->rear;
    for (; temp; temp = temp->next) {
        sfVector2f pos;
        bullet_t *bl;
        bl = temp->obj;
        bl->life--;
        if (bl->life < 1)
            continue;
        bl->pos = (sfVector2f){
            bl->pos.x + bl->speed.x * s, bl->pos.y + bl->speed.y * s
        };
        pos = (sfVector2f){
            bl->pos.x - bl->radius, bl->pos.y - bl->radius
        };
        sfCircleShape_setPosition(bl->body, pos);
        sfRenderWindow_drawCircleShape(*win, bl->body, NULL);
    }
}
