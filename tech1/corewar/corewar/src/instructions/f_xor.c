/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_xor.c
*/

#include "corewar.h"

// 0x08 (xor) Similar to and, but performing a binary XOR (exclusive OR).

void f_xor(corewar_t *cw, champs_t *iter)
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
    ^ iter->regs[iter->code.params[0]];
    cw->carry = 0;
}
