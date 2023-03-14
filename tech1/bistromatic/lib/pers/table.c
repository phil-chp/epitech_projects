/*
** EPITECH PROJECT, 2020
** Table
** File description:
** Mallocs our eval->temp table and calls make_table()
*/

#include <stdlib.h>
#include "eval_expr_struct.h"
#include "pers.h"
#include "my.h"

void table(t_eval *eval, char *calc)
{
    int k = 2;

    eval->len = my_strlen(calc);
    if (eval->len < 4)
        k = 0;
    calc = minus_check(eval, calc);
    eval->temp = malloc(sizeof(char *) * (eval->len + 10));
    if (k == 2)
        secure_zero(eval);
    make_table(eval, calc, k);
    check_minus(eval);
    return;
}
