/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** get_center.c
*/

#include <SFML/Graphics.h>

sfVector2f get_center(sfVector2f size_a, sfVector2f size_b)
{
    sfVector2f temp;

    size_a.x /= 2;
    size_a.y /= 2;
    size_b.x /= 2;
    size_b.y /= 2;
    temp.x = size_a.x - size_b.x;
    temp.y = size_a.y - size_b.y;
    return temp;
}
