/*
** EPITECH PROJECT, 2020
** Values Check
** File description:
** Checks if baes and ops are different.
*/

#include <stdlib.h>
#include "bistromatic.h"
#include "eval_expr_struct.h"

static void error_exits(t_eval *eval, int n, int i, int j)
{
    if (n == 0)
        if (eval->base[i][0] == eval->ops[j][0]) {
            SYNTAX_ERROR_MSG;
            exit(EXIT);
        }
    if (n == 1)
        if (eval->base[i][0] == eval->base[j][0]) {
            SYNTAX_ERROR_MSG;
            exit(EXIT_BASE);
        }
    if (n == 2)
        if (eval->ops[i][0] == eval->ops[j][0]) {
            SYNTAX_ERROR_MSG;
            exit(EXIT_OPS);
        }

}

void values_check(t_eval *eval)
{
    int i;
    int j;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 7; j++)
            error_exits(eval, 0, i, j);
    for (i = 0; i < 10; i++)
        for (j = i + 1; j < 10; j++)
            error_exits(eval, 1, i, j);
    for (i = 0; i < 7; i++)
        for (j = i + 1; j < 7; j++)
            error_exits(eval, 2, i, j);
    return;
}