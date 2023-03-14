/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** f_ldi.c
*/

// 0x0a (ldi) takes 3 parameters. The first two must be indexes,
// the third one must be a register.
// This operation modifies the carry.
// ldi 3,%4,r1 reads IND_SIZ bytes from the
// address PC + 3 % IDX_MOD, adds 4 to this value.
// The sum is named S. REG_SIZE bytes are read from the address
// PC + S % IDX_MOD and copied into r1.

#include "corewar.h"
#include "shared.h"

void f_ldi(corewar_t *cw, champs_t *iter)
{
    number_u tmp;
    int size;
    int pos;

    for (size_t i = 0; i < 3; i++) {
        if (iter->code.params[i] == 0U || iter->code.params[i] > 15U) {
            cw->carry = 1;
            return;
        }
    }
    for (register short j = 0; iter->code.types[j] != 0; j++) {
        tmp.nb = 0;
        size = (iter->code.types[j] == T_DIR ? 2 : 4);
        pos = (iter->code.types[j] == T_DIR ? iter->code.params[j]  \
        : iter->code.params[j] + iter->pos);
        for (register short i = 0; i < size; i++)
            tmp.c[i] = cw->arena[pos + i];
    }
    iter->regs[iter->code.params[2]] = iter->pos + 3 % IDX_MOD + 4;
    cw->carry = 0;
}
