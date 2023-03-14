/*
** EPITECH PROJECT, 2020
** Is Base
** File description:
** Compares char to our base of numbers given by user
*/

#include <stdlib.h>
#include "eval_expr_struct.h"

int is_base(t_eval *eval, char calc)
{
    char original_base[] = "1234567890";

    if (calc == 0)
        return (0);
    for (int i = 0; i < 10; i++)
        if (calc == original_base[i])
            return (1);
}