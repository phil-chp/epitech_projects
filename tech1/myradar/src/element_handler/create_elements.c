/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** create_circle
*/

#include <stdlib.h>
#include "struct.h"
#include "lib.h"
#include "my.h"

sfSprite *create_plane(sfVector2f position, float size)
{
    sfVector2f v_size = {size * 0.01, size * 0.01};
    sfSprite *p_sprite;
    sfTexture *plane;

    plane = sfTexture_createFromFile("assets/plane.png", NULL);
    p_sprite = sfSprite_create();
    sfSprite_setTexture(p_sprite, plane, sfFalse);
    sfSprite_setPosition(p_sprite, position);
    sfSprite_setScale(p_sprite, v_size);
    return (p_sprite);
}

sfSprite *create_tower(sfVector2f position, float radius)
{
    sfVector2f v_size = {radius * 0.004, radius * 0.004};
    sfVector2f v_move = {radius / 1.35, radius / 1.55};
    sfSprite *t_sprite;
    sfTexture *tower;

    tower = sfTexture_createFromFile("assets/tower.png", NULL);
    t_sprite = sfSprite_create();
    sfSprite_setTexture(t_sprite, tower, sfFalse);
    sfSprite_setPosition(t_sprite, position);
    sfSprite_setScale(t_sprite, v_size);
    sfSprite_move(t_sprite, v_move);
    return (t_sprite);
}

sfCircleShape *show_tower_area(sfVector2f position, \
                                sfColor outline, float radius)
{
    sfCircleShape *tower_area;

    tower_area = sfCircleShape_create();
    sfCircleShape_setOutlineColor(tower_area, outline);
    sfCircleShape_setFillColor(tower_area, sfTransparent);
    sfCircleShape_setOutlineThickness(tower_area, 2.0);
    sfCircleShape_setPosition(tower_area, position);
    sfCircleShape_setRadius(tower_area, radius);
    return (tower_area);
}
