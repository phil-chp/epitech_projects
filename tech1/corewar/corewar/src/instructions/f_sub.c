/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_sub.c
*/

#include "corewar.h"

// 0x05 (sub) Similar to add, but performing a subtraction.#include "corewar.h"

void f_sub(corewar_t *cw, champs_t *iter)
{
    for (size_t i = 0; i < 3; i++) {
        if (iter->code.params[i] == 0U || iter->code.params[i] > 15U) {
            cw->carry = 1;
            return;
        }
    }
    iter->regs[iter->code.params[2]]    \
    = iter->regs[iter->code.params[1]]  \
    - iter->regs[iter->code.params[0]];
    cw->carry = 0;
}
