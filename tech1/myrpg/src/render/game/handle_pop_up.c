/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** handle_pop_up
*/

#include "my_rpg.h"

void handle_pop_up(entity_t *pl, entity_t *pnj)
{
    sfFloatRect area = (sfFloatRect) {  pnj->pos.x - 30,
                                        pnj->pos.y - 30,
                                        pnj->size.x + 60,
                                        pnj->size.y + 60};

    pnj->pop_up.enabled = (GET_COLLISION_CENTER(pl->pos, area) ? true : false);
}
