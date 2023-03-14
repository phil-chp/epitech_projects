/*
** EPITECH PROJECT, 2020
** count zero
** File description:
** point next zero
*/
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "pers.h"

char *retirezero(char *res)
{
    int u = 0, p = 0, len3 = my_strlen(res);
    char *mul;

    mul = malloc(sizeof(char) * (len3 + 1));
    if (res[u] == '\0') {
        res = "0\0";
        return (res);
    }
    if (res[u] != '0')
            return (res);
    while (res[u] == '0' && u < len3 - 1)
        u++;
    mul = retiringzero(res, mul, p, u);
    return (mul);
}
