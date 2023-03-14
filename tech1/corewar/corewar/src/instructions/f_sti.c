/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_sti.c
*/

#include "corewar.h"

// 0x0b (sti) takes 3 parameters. The first one must be a register.
// The other two can be indexes or registers.
// sti r2,%4,%5 copies the content of r2 into the address PC + (4+5)% IDX_MOD.

void f_sti(corewar_t *cw, champs_t *iter)
{
    if (cw) {}
    if (iter->code.params[0] == 0U || iter->code.params[0] > 15U) {
        return;
    }
}
