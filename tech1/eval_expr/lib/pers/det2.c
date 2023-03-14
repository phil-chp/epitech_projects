/*
** EPITECH PROJECT, 2020
** det 2
** File description:
** - - = -
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pers.h"

char *det2(int i, int j, char *p1, char *p2)
{
    char *s3 = NULL;
    int u = 0, p = 0, a = i + 1, ret = 0;

    s3 = malloc(sizeof(char) * (i + 4));
    while (u != a) {
        if ((p1[i] + p2[j] + ret - 48) <= 57) {
            s3[p] = p1[i] + ret + p2[j] - 48;
            ret = 0;
        }
        ((p1[i] + p2[j] + ret - 48) > 57)                       \
            && (s3[p] = p1[i] + ret + p2[j] - 48 - 10, ret = 1);
        p++, u++, j--, i--;
    }
    s3 = checkzero(s3);
    (ret == 1) ? (s3[p] = '1', s3[p + 1] = '-', s3[p + 2] = '\0')       \
        : (s3[p] = '-', s3[p + 1] = '\0');
    my_revstr(s3);
    return (s3);
}
