/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_or.c
*/

// 0x07 (or) Similar to and, but performing a binary OR.

#include "corewar.h"

void f_or(corewar_t *cw, champs_t *iter)
{
    for (size_t i = 0; i < 3; i++) {
        if (iter->code.params[i] == 0U || iter->code.params[i] > 15U) {
            cw->carry = 1;
            return;
        }
    }
    if (iter->code.params[1] && iter->code.params[0])
    iter->regs[iter->code.params[2]]    \
    = iter->regs[iter->code.params[1]]  \
    | iter->regs[iter->code.params[0]];
    cw->carry = 0;
}
