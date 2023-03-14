/*
** EPITECH PROJECT, 2020
** Make Table
** File description:
** Creates the table from the list of
** characters (expression) given by user
*/

#include <stdlib.h>
#include "eval_expr_struct.h"
#include "pers.h"
#include "my.h"

static int next_malloc(t_eval *eval, char *calc, int k, int i)
{
    if (IS_BASE) {
        eval->temp[k] = malloc(sizeof(char) * (num_count(calc, i) + 1));
    }
    return (0);
}

void make_table(t_eval *eval, char *calc, int k)
{
    int i = 0, j = 1, z = 0;

    for (i = 0; i < eval->len; i++) {
        z = next_malloc(eval, calc, k, i);
        for (j = 0; IS_BASE; j++, i++, z++) {
            eval->temp[k][j] = calc[i];
            eval->temp[k][j + 1] = '\0';
        }
        (z > 0) && (k++);
        if (IS_OPS) {
            eval->temp[k] = malloc(sizeof(char) * 2);
            eval->temp[k][0] = calc[i];
            eval->temp[k][1] = '\0';
            k++;
        }
    }
    eval->temp[k] = malloc(sizeof(char));
    eval->temp[k] = NULL;
    eval->len = k;
    return;
}
