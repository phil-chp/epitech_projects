/*
** EPITECH PROJECT, 2020
** det1
** File description:
** + + = +
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pers.h"

char *det1(int i, int j, char *p1, char *p2)
{
    char *s3;
    s3 = malloc(sizeof(char) * (i+3));
    int u = 0, p = 0, a = 0, ret = 0;
    a = i + 1;
    while (u != a) {
        if ((p1[i] + p2[j] + ret - 48) <= 57)
            s3[p] = p1[i] + ret + p2[j] - 48, ret = 0;
        if ((p1[i] + p2[j] + ret - 48) > 57)
            s3[p] = p1[i] + ret + p2[j] - 48 - 10, ret = 1;
        p++, u++, j--, i--;
    }
    if (ret == 1) {
        s3[p] = '1';
        s3[p+1] = '\0';
    }
    else
        s3[p] = '\0';
    s3 = checkzero(s3);
    s3 = my_revstr(s3);
    return s3;
}
