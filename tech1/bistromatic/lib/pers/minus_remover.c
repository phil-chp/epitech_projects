/*
** EPITECH PROJECT, 2020
** Minus Remover
** File description:
** Removes minus signs accroding to sign
*/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "eval_expr_struct.h"
#include "pers.h"

static char *minus_remover(t_eval *eval, char *str, int i)
{
    int nbmoins = 0;
    int k = i;

    for (i; str[i] == '-' || str[i] == '+'; i++)
        (str[i] == '-') ? (nbmoins++) : 0;
    if (nbmoins % 2 == 1) {
        str[k] = '-';
        k++;
        for (i; str[i] != '\0'; k++, i++)
            str[k] = str[i];
    } else {
        if (k != 0 && (str[k - 1] >= '0' && str[k - 1] <= '9')) {
            str[k] = '+';
            k++;
        }
        for (i; str[i] != '\0'; k++, i++)
            str[k] = str[i];
    }
    str[k] = '\0';
    eval->len = my_strlen(str);
    return (str);
}

char *minus_check(t_eval *eval, char *str)
{
    for (int i = 1; str[i + 1] != '\0'; i++) {
        if (str[i] == '-') {
            minus_remover(eval, str, i);
        }
    }
    return (str);
}
