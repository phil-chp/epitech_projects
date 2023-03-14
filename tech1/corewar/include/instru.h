/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** instru.h
*/

#ifndef INS_H_
#define INS_H_

#include "corewar.h"

void (*ins[17])(corewar_t *cw, champs_t *iter) = {
    0,
    f_live,
    f_ld,
    f_st,
    f_add,
    f_sub,
    f_and,
    f_or,
    f_xor,
    f_zjmp,
    f_ldi,
    f_sti,
    f_fork,
    f_lld,
    f_lldi,
    f_lfork,
    f_aff
};

#endif /* INS_H_ */
