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

void make_table(t_eval *eval, char const *calc, int k)
{
    int i = 0, j = 1;
    int len = eval->len;

    for (i = 0; i < len; i++) {
        eval->temp[k] = malloc(sizeof(char *) * 10);
        for (j = 0; IS_BASE; j++, i++) {
            (j != 0) && (k--, eval->len -= 1);
            eval->temp[k][j] = calc[i];
            eval->temp[k][j + 1] = '\0';
            k++;
        }
        if (IS_OPS) {
            eval->temp[k] = malloc(sizeof(char) * 2);
            eval->temp[k][0] = calc[i];
            eval->temp[k][1] = '\0';
            k++;
        }
    }
    eval->temp[k] = 0;
    return;
}
