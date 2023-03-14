/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_fork.c
*/

#include "corewar.h"

// 0x0c (fork) takes 1 parameter, which must be an index.
// It creates a new program that inherits different
// states from the parent. This program is executed at the address
// PC + first parameter % IDX_MOD.

void f_fork(corewar_t *cw, champs_t *iter)
{
    champs_t *child = NULL;
    unsigned int res;

    if (iter->code.params[0] > MEM_SIZE) {
        res = iter->code.params[0] % MEM_SIZE;
        iter->code.params[0] -= res * MEM_SIZE;
    }
    init_fork(child, iter);
    child->pos = iter->pos + iter->code.params[0] % IDX_MOD;
}
