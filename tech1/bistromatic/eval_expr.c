/*
** EPITECH PROJECT, 2020
** Eval Expr
** File description:
** evaluates expressions
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "eval_expr_struct.h"
#include "pers.h"

void eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
    t_eval *eval;
    int i;

    eval = malloc(sizeof(t_eval));
    eval = new_eval(eval, base, ops, size);
    values_check(eval);
    table(eval, expr);
    module(eval->temp);
    my_putstr(eval->temp[0]);
    for (i = 0; eval->base[i]; i++)
        free(eval->base[i]);
    for (i = 0; eval->ops[i]; i++)
        free(eval->ops[i]);
    free(eval->base);
    free(eval->ops);
    free(eval->temp);
    free(eval);
    return;
}