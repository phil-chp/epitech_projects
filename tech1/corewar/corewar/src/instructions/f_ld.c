/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_ld.c
*/

// 0x02 (ld) takes 2 parameters.
// It loads the value of the first parameter into the second parameter,
// which must be a register (not the PC). This operation modifies the carry.
// ld 34,r3 loads the REG_SIZE bytes starting at
// the address PC + 34 % IDX_MOD into r3

#include "corewar.h"

void f_ld(corewar_t *cw, champs_t *iter)
{
    __u_int temp = 0;

    if (iter->code.params[1] == 0U || iter->code.params[1] > 15U) {
        cw->carry = 1;
        return;
    }
    cw->carry = 0;
    if (iter->code.types[0] == T_DIR)
    iter->regs[iter->code.params[1] - 1] = iter->code.params[0];
}
