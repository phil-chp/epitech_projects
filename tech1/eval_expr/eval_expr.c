/*
** EPITECH PROJECT, 2020
** Eval Expr
** File description:
** Evualtes Expressions using POMDAS order
*/

#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "eval_expr_struct.h"
#include "pers.h"

int eval_expr(char const *str)
{
    t_eval *eval;

    eval = malloc(sizeof(t_eval));
    eval = new_eval(eval, str);
    table(eval, str);
    module(eval->temp);
    free(eval);
    return (my_getnbr(eval->temp[0]));
}
