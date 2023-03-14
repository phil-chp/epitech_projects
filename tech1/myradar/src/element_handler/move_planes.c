/*
** EPITECH PROJECT, 2020
** my_radar (Workspace)
** File description:
** move_circles
*/

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "lib.h"

#include <stdio.h>

sfVector2f define_move(pos_t *pos, sfVector2f c, int i)
{
    float x, y;
    float value;

    x = pos->p_dest[i].x - c.x;
    y = pos->p_dest[i].y - c.y;
    value = sqrt(x * x + y * y);
    c.x = (x / value) * (float)pos->p_speed[i];
    c.y = (y / value) * (float)pos->p_speed[i];
    return (c);
}

void move_planes(vars_t *va, pos_t *pos)
{
    for (int j = 0; j < pos->t_count; j++) {
        sfRenderWindow_drawSprite(va->window, pos->towers[j], NULL);
        sfRenderWindow_drawCircleShape(va->window, pos->towers_area[j], NULL);
    }
    for (int i = 0;  i < pos->p_count; i++) {
        sfVector2f c = sfSprite_getPosition(pos->planes[i]);
        if (!(c.x < -450 && c.y < -450)) {
            sfVector2f move = define_move(pos, c, i);
            sfSprite_move(pos->planes[i], move);
            sfRenderWindow_drawSprite(va->window, pos->planes[i], NULL);
        }
    }
}
