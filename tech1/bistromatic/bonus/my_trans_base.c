/*
** EPITECH PROJECT, 2020
** My Trans Base
** File description:
** Transforms bases and operators
*/

#include <stddef.h>
#include "my.h"
#include "eval_expr_struct.h"

static void my_decrypt(t_eval *eval, char *calc, int i)
{
    char original_base[] = "1234567890";
    char original_ops[] = "()+-*/%";

    for (int j = 0; eval->base[j]; j++)
        if (calc[i] == eval->base[j][0])
            calc[i] = original_base[j];
    for (int k = 0; eval->ops[k]; k++)
        if (calc[i] == eval->ops[k][0])
            calc[i] = original_ops[k];
    return;
}

static void my_crypt(t_eval *eval, char *calc, int i, int n)
{
    char original_base[] = "1234567890";
    char original_ops[] = "()+-*/%";

    for (int j = 0; eval->base[j] && n == 0; j++) {
        if (eval->temp[0][i] == original_base[j]) {
            if (eval->temp[0][i] == '0' && j == 9)
                n = 1;
            else {
                eval->temp[0][i] = eval->base[j][0];
                n = 1;
            }
        }
    }
    for (int k = 0; eval->ops[k] && n == 0; k++) {
        if (eval->temp[0][i] == original_ops[k]) {
            eval->temp[0][i] = eval->ops[k][0];
            n = 1;
        }
    }
    return;
}

void my_trans_base(t_eval *eval, char *calc)
{
    int i;

    if (calc == NULL) {
        eval->len = my_strlen(eval->temp[0]);
        for (i = 0; eval->temp[0][i]; i++)
            my_crypt(eval, calc, i, 0);
    } else
        for (i = 0; calc[i]; i++)
            my_decrypt(eval, calc, i);
    return;
}