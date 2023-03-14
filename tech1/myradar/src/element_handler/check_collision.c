/*
** EPITECH PROJECT, 2020
** my_radar (Workspace)
** File description:
** check_collision
*/

#include <math.h>
#include "struct.h"
#include "lib.h"

int check_if_in_tower(pos_t *pos, sfVector2f a, sfVector2f b)
{
    for (int i = 0; i < pos->t_count; i++) {
        sfVector2f c = sfCircleShape_getPosition(pos->towers_area[i]);
        if (pow(a.x - c.x, 2) + pow(a.y - c.y, 2) <= pow(pos->t_radius[i], 2))
            return (1);
        if (pow(b.x - c.x, 2) + pow(b.y - c.y, 2) <= pow(pos->t_radius[i], 2))
            return (1);
    }
    return (0);
}

static void compare_planes(pos_t *pos, int i, int j)
{
    sfVector2f x = {-500, -500};
    sfVector2f a;
    sfVector2f b;

    a = sfSprite_getPosition(pos->planes[i]);
    b = sfSprite_getPosition(pos->planes[j]);
    if (a.x < -450 || b.x < -450)
        return;
    if (check_if_in_tower(pos, a, b) == 1)
        return;
    if (a.x < b.x + PLANE_SIZE && a.x + PLANE_SIZE > b.x                \
                    && a.y < b.y + PLANE_SIZE && a.y + PLANE_SIZE > b.y) {
        sfSprite_setPosition(pos->planes[i], x);
        sfSprite_setPosition(pos->planes[j], x);
    }
}

static int check_plane_trajectory(pos_t *pos, int i)
{
    sfVector2f x = {-500, -500};
    sfVector2f a;

    a = sfSprite_getPosition(pos->planes[i]);
    if (a.x < -450 || a.y < -450)
        return (1);
    if (a.x >= pos->p_dest[i].x - 1 && a.y >= pos->p_dest[i].y - 1) {
        sfSprite_setPosition(pos->planes[i], x);
        return (1);
    }
    return (0);
}

void check_collision(pos_t *pos)
{
    for (int i = 0; i < pos->p_count; i++) {
        if (check_plane_trajectory(pos, i) == 1)
            i++;
        for (int j = 0; i < pos->p_count && j < pos->p_count; j++) {
            (j == i) && (j++, 0);
            (j < pos->p_count) && (compare_planes(pos, i, j), 0);
        }
    }
}
