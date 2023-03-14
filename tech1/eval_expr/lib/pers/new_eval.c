/*
** EPITECH PROJECT, 2020
** New Eval
** File description:
** Defines and malloc's every component of the typedef struct s_eval {} t_eval;
*/

#include <stdlib.h>
#include "eval_expr_struct.h"
#include "my.h"

t_eval *new_eval(t_eval *eval, char const *str)
{
    int i, j;
    char base[] = "1234567890";
    char ops[] = "()+-*/%";

    eval->base = malloc(sizeof(char *) * 11);
    eval->ops = malloc(sizeof(char *) * 8);
    for (i = 0; i < 11; i++) {
        eval->base[i] = malloc(sizeof(char) * 2);
        eval->base[i][0] = base[i];
        eval->base[i][1] = '\0';
    }
    eval->base[i] = 0;
    for (j = 0; j < 8; j++) {
        eval->ops[j] = malloc(sizeof(char) * 2);
        eval->ops[j][0] = ops[j];
        eval->ops[j][1] = '\0';
    }
    eval->ops[j] = 0;
    eval->len = my_strlen(str);
    return (eval);
}
