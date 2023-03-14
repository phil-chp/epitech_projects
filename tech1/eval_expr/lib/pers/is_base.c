/*
** EPITECH PROJECT, 2020
** Is Base
** File description:
** Compares char to our base of numbers given by user
*/

#include "eval_expr_struct.h"

int is_base(t_eval *eval, char calc)
{
    for (int i = 0; i < 10; i++) {
        if (calc == eval->base[i][0])
            return (1);
    }
    return (0);
}
