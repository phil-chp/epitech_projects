/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_add.c
*/

#include "corewar.h"

// 0x04 (add) takes 3 registers as parameters.
// It adds the content of the first two and // puts the sum
// into the third one (which must be a register).
// This operation modifies the carry.
// add r2,r3,r5 adds the content of r2 and r3 and // puts the result into r5.

void f_add(corewar_t *cw, champs_t *iter)
{
    for (size_t i = 0; i < 3; i++) {
        if (iter->code.params[i] == 0U || iter->code.params[i] > 15U) {
            cw->carry = 1;
            return;
        }
    }
    iter->regs[iter->code.params[2]]    \
    = iter->regs[iter->code.params[1]]  \
    + iter->regs[iter->code.params[0]];
    cw->carry = 0;
}
