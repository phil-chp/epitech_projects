/*
** EPITECH PROJECT, 2020
** New Eval
** File description:
** Defines and malloc's every component of the typedef struct s_eval {} t_eval;
*/

#include <stdlib.h>
#include "eval_expr_struct.h"
#include "my.h"

t_eval *new_eval(t_eval *eval, char *base, char *ops, int size)
{
    int i;

    eval->base = malloc(sizeof(char *) * (10 + 1));
    eval->ops = malloc(sizeof(char *) * (7 + 1));
    eval->len = size;
    set_calc(eval, base);
    set_calc(eval, ops);
    return (eval);
}
