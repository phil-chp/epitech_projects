/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** handle_health.c
*/

#include "my_rpg.h"

bool handle_health_bar(entity_t **entity)
{
    sfFloatRect pos;

    pos = sfRectangleShape_getGlobalBounds((*entity)->body);
    sfVector2f health_size = {100, 15};
    sfVector2f size_bg = {health_size.x - 2 + (*entity)->stats.health,  \
                    health_size.y - 2};
    sfVector2f pos_bg = {pos.left - 10, pos.top - 10};
    pos.left += 9;
    (*entity)->health.bar = create_rectangle(pos_bg, size_bg, NULL);
    (*entity)->health.background = create_rectangle(pos_bg, size_bg, NULL);
    sfRectangleShape_setFillColor((*entity)->health.bar, sfRed);
    sfRectangleShape_setFillColor((*entity)->health.background, sfBlack);
    return (0);
}
