/*
** EPITECH PROJECT, 2020
** Is Ops
** File description:
** Compares a char to our operators given by user
*/

#include "eval_expr_struct.h"

int is_ops(t_eval *eval, char calc)
{
    for (int i = 0; i < 7; i++)
        if (calc == eval->ops[i][0])
            return (1);
    return (0);
}
