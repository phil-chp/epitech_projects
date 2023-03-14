/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** get_advancement
*/

#include <SFML/Graphics.h>

void normalize(sfVector2f *vector);

sfVector2f get_advancement(sfVector2f a, sfVector2f b)
{
    sfVector2f res;

    res.x = b.x - a.x;
    res.y = b.y - a.y;
    normalize(&res);
    return (res);
}
