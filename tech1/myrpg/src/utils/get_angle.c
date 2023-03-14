/*
** EPITECH PROJECT, 2021
** myRPG (Workspace)
** File description:
** get_angle
*/

#include <SFML/Graphics.h>
#include <math.h>

double get_angle(sfVector2i b, sfVector2i a)
{
    sfVector2i delta;
    double angle;

    delta.x = a.x - b.x;
    delta.y = a.y - b.y;
    angle = atan2(delta.y, delta.x);
    angle = angle * 180 / M_PI - 90;
    return (angle);
}

double get_anglef(sfVector2f b, sfVector2f a)
{
    sfVector2i ai;
    sfVector2i bi;

    bi = (sfVector2i){(int)b.x, (int)b.y};
    ai = (sfVector2i){(int)a.x, (int)a.y};
    return (get_angle(bi, ai));
}
