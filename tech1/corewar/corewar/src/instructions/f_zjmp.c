/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_zjmp.c
*/

// 0x09 (zjmp) takes 1 parameter, which must be an index.
// It jumps to this index if the carry is worth 1.
// Otherwise, it does nothing but consumes the same time.
// zjmp %23 // puts, if carry equals 1, PC + 23 % IDX_MOD into the PC

#include "corewar.h"

void f_zjmp(corewar_t *cw, champs_t *iter)
{
    op_t op = op_tab[8];
    unsigned int res;

    if (!cw->carry) return;
    if (iter->code.params[0] > MEM_SIZE) {
        res = iter->code.params[0] % MEM_SIZE;
        iter->code.params[0] -= res * MEM_SIZE;
    }
    iter->pos += iter->code.params[0] + 23 % IDX_MOD;
}
