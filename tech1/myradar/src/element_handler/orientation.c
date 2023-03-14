/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myradar-vitali.droujko [WSL: Ubuntu]
** File description:
** fill_array.c
*/

#include <math.h>
#include "struct.h"
#include "my.h"

static float get_orientation(pos_t *pos, int i)
{
    sfVector2f current_pos;
    float difference = 0;
    float value;
    float angle;
    float x, y;

    current_pos = sfSprite_getPosition(pos->planes[i]);
    x = pos->p_dest[i].x - current_pos.x;
    y = pos->p_dest[i].y - current_pos.y;
    value = sqrt(x * x + y * y);
    angle = acos(x / value) * 180.0 / M_PI;
    if (pos->p_dest[i].y < current_pos.y)
        difference = 22.5 - angle;
    angle += 2 * difference;
    return (angle);
}

void set_orientation(pos_t *pos)
{
    for (int i = 0; i < pos->p_count; i++) {
        float angle = get_orientation(pos, i);
        sfSprite_setRotation(pos->planes[i], angle);
    }
}
