/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** destroy_arena.c
*/

#include <stdlib.h>
#include "corewar.h"

static void destroy_champs(champs_t *champs)
{
    if (champs->code_byte) free(champs->code_byte);
    if (champs->code.params) free(champs->code.params);
    free(champs);
}

void destroy_features(corewar_t *cw)
{
    champs_t *temp_two;
    code_t *temp;

    if (cw->alive) free(cw->alive);
    if (cw->arena) free(cw->arena);
    if (!cw->champs->head) return;
    for (champs_t *iter_champs = cw->champs->head; iter_champs; ) {
        temp_two = iter_champs;
        iter_champs = iter_champs->next;
        destroy_champs(temp_two);
    }
}
