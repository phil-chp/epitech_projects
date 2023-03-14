/*
** EPITECH PROJECT, 2020
** Retiring Zero
** File description:
** Removes the zeros
*/

#include "my.h"

char *retiringzero(char *res, int u)
{
    int p = 0;

    if (u == my_strlen(res)) {
        res[p] = res[u];
    }
    else {
        while (res[u] != '\0') {
            res[p] = res[u];
            u++, p++;
        }
    }
    res[p] = '\0';
    return (res);
}
