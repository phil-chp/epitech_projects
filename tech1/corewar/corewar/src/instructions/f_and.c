/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_and.c
*/

// 0x06 (and) takes 3 parameters.
// It performs a binary AND between the first two parameters
// and stores the result into the third one (which must be a register).
// This operation modifies the carry.
// and r2, %0,r3 // puts r2 & 0 into r3.

#include "corewar.h"
#include "shared.h"

void f_and(corewar_t *cw, champs_t *iter)
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
    & iter->regs[iter->code.params[0]];
    cw->carry = 0;
}
