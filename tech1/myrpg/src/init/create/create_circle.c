/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_circle
*/

#include <SFML/Graphics.h>

sfCircleShape *create_circle(sfVector2f pos, float radius, sfTexture *texture)
{
    sfCircleShape *circle;

    if (!(circle = sfCircleShape_create()))
        return (NULL);
    if (pos.x > -1)
        sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, radius);
    if (texture)
        sfCircleShape_setTexture(circle, texture, sfFalse);
    return (circle);
}
