/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** handle_animation
*/

#include "my_rpg.h"

void handle_animation(entity_t **entity)
{
    sfVector2u size;
    sfIntRect rect;

    rect = sfRectangleShape_getTextureRect((*entity)->body);
    size = sfTexture_getSize(sfRectangleShape_getTexture((*entity)->body));
    if (((unsigned int) (rect.left + rect.width)) < (size.x) \
    && (unsigned int) (rect.top + rect.height) <= (size.y - rect.height))
        rect.left += rect.width;
    else
        rect.left = 0;
    sfRectangleShape_setTextureRect((*entity)->body, rect);
}
