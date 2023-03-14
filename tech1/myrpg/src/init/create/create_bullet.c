/*
** EPITECH PROJECT, 2021
** my_rpg (Workspace)
** File description:
** create_bullet
*/

#include <stdlib.h>
#include "my_rpg.h"

bool create_bullet(bullet_t **bullet)
{
    sfVector2f pos;

    pos = (sfVector2f){ -1, -1 };

    (*bullet) = malloc(sizeof(bullet_t));
    (*bullet)->texture = NULL;
    (*bullet)->motion  = 10;
    (*bullet)->radius  = 10;
    (*bullet)->life    = 480;
    (*bullet)->scale   = (sfVector2f){ 1.0, 1.0 };
    (*bullet)->mask    = (sfColor){ 255, 0, 0, 127 };
    (*bullet)->body = create_circle(pos, (*bullet)->radius, (*bullet)->texture);
    if ((*bullet)->body == NULL)
        return (1);
    sfCircleShape_setFillColor((*bullet)->body, (*bullet)->mask);
    return (0);
}
