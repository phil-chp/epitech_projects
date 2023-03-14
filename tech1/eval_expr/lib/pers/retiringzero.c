/*
** EPITECH PROJECT, 2020
** Retiring Zero
** File description:
** Removes the zeros
*/

#include "my.h"

char *retiringzero(char *res, char *mul, int p, int u)
{
    if (u == my_strlen(res))
        mul[p] = res[u];
    else {
        while (res[u] != '\0') {
            mul[p] = res[u];
            u++, p++;
        }
    }
    mul[p + 1] = '\0';
    return (mul);
}
