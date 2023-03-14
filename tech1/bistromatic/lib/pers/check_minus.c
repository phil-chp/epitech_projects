/*
** EPITECH PROJECT, 2020
** Check Minus
** File description:
** Checks for negative signs and concatenates them with the following number
** under special conditions. Only if it is followed by an int and there is no
** parenthesis before. Also it can't be preceded by an int.
*/

#include "eval_expr_struct.h"
#include "my.h"

char *setminus(char *str);

static void rem_minus(t_eval *eval, int i)
{
    if (is_base(eval, eval->temp[i + 1][0]) == 1            \
        && is_ops(eval, eval->temp[i - 1][0]) == 1          \
        && eval->temp[i - 1][0] != eval->base[1][0]         \
        && eval->temp[i - 1][0] != eval->base[0][0]) {
        eval->temp[i + 1] = setminus(eval->temp[i + 1]);
        while (i + 1 < eval->len) {
            eval->temp[i] = my_strdup(eval->temp[i + 1]);
            i++;
        }
        eval->temp[i] = 0;
        eval->len--;
        check_minus(eval);
    }
    return;
}

void check_minus(t_eval *eval)
{
    int i = 0;

    if (eval->len < 3)
        return;
    while (i < eval->len - 1) {
        if (eval->temp[i][0] == eval->base[3][0]
            && my_strlen(eval->temp[i]) == 1)
            rem_minus(eval, i);
        i++;
    }
    return;
}
