/*
** EPITECH PROJECT, 2020
** Is Ops
** File description:
** Compares a char to our operators given by user
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "eval_expr_struct.h"

int is_ops(t_eval *eval, char calc)
{
    char original_ops[] = "()+-*/%";
    int j = 0;

    if (calc == 0 || (calc >= '0' && calc <= '9'))
        return (0);
    for (int i = 0; i < 7; i++) {
        if (calc == original_ops[i])
            return (1);
        else
            j++;
        if (j >= 7) {
            SYNTAX_ERROR_MSG;
            exit(EXIT_OPS);
        }
    }
    return (0);
}