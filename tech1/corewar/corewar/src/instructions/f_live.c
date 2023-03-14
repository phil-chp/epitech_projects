/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_live.c
*/

#include "corewar.h"

// 0x01 (live) takes 1 parameter: 4 bytes that represent the player’s number.
// It indicates that the player is alive

void f_live(corewar_t *cw, champs_t *iter)
{
    if (iter->code.params[0] <= (unsigned)cw->teams) {
        cw->alive[iter->code.params[0] - 1] = 1;
    }
}
