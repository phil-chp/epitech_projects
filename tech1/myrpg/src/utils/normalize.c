/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** get_norm
*/

#include <math.h>
#include "my_rpg.h"

double pythagoreas(int x, int y)
{
    return (sqrt(pow(x, 2) + pow(y, 2)));
}

void normalize(sfVector2f *vector)
{
    double v;

    if (vector->x == 0 && vector->y == 0)
        return;
    v = pythagoreas(vector->x, vector->y);
    v = sqrt(v);
    vector->x /= v;
    vector->y /= v;
}
