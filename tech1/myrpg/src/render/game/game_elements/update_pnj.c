/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-myrpg-theo.guichard
** File description:
** update_pnj.c
*/

#include "my_rpg.h"

void update_pnj(sfRenderWindow **win, entity_t *pnj)
{
    if (!pnj->body)
        return;
    sfRenderWindow_drawRectangleShape(*win, pnj->body, NULL);
    update_pop_up(win, &pnj->pop_up);
}
