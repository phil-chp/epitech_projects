/*
** EPITECH PROJECT, 2020
** Set Calc
** File description:
** Defines and malloc's the size of the list given
** (base and ops in our case, see new_eval(); )
*/

#include <stdlib.h>
#include "eval_expr_struct.h"
#include "my.h"

void set_calc(t_eval *eval, char *calc)
{
    int i = 0;

    eval->temp = malloc(sizeof(char *) * (my_strlen(calc) + 1));
    for (i = 0; calc[i] != '\0'; i++) {
        eval->temp[i] = malloc(sizeof(char) + 1);
        eval->temp[i][0] = calc[i];
        eval->temp[i][1] = '\0';
    }
    eval->temp[i] = malloc(sizeof(char));
    eval->temp[i] = NULL;
    if (my_strlen(calc) == 7)
        eval->ops = eval->temp;
    else
        eval->base = eval->temp;
    return;
}
