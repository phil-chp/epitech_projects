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
#include "pers.h"

char *retirezero(char *res)
{
    int u = 0, len3 = my_strlen(res);

    if (res[u] == '\0') {
        res = "0\0";
        return (res);
    }
    if (res[u] != '0') {
        return (res);
    }
    while (res[u] == '0' && u < (len3 - 1) && res[u] != '\0')
        u++;
    res = retiringzero(res, u);
    return (res);
}
