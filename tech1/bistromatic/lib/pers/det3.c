/*
** EPITECH PROJECT, 2020
** det3
** File description:
** + - = + || - + = +
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "pers.h"

char *det3(int i, int j, char *p1, char *p2)
{
    char *s3;
    int u = 0, p = 0, a = i + 1, ret = 0, len1, len2;

    s3 = malloc(sizeof(char) * (i + 3));
    while (u != a) {
        if ((p2[i] - p1[j] - ret + 48) >= 48) {
            s3[p] = p2[i] - ret - p1[j] + 48;
            ret = 0;
        }
        else {
            s3[p] = p2[i] - ret - p1[j] + 48 + 10;
            ret = 1;
        }
        p++, u++, j--, i--;
    }
    s3[p] = '\0';
    s3 = checkzero(s3);
    my_revstr(s3);
    return (s3);
}
