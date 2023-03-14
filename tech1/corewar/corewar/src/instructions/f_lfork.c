/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_lfork.c
*/

#include "corewar.h"

// 0x0f (lfork) Similar to fork without the % IDX_MOD.

void f_lfork(corewar_t *cw, champs_t *iter)
{
    champs_t *child = NULL;
    unsigned int res;

    if (iter->code.params[0] > MEM_SIZE) {
        res = iter->code.params[0] % MEM_SIZE;
        iter->code.params[0] -= res * MEM_SIZE;
    }
    init_fork(child, iter);
    child->pos = iter->pos + iter->code.params[0];
}
