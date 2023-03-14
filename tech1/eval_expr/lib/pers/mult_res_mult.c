/*
** EPITECH PROJECT, 2020
** str * str add in **s
** File description:
** module for multiplication
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "pers.h"

char **mult_res_mult(char *p1, char *p2, char **s3)
{
    int len1 = my_strlen(p1), len2 = my_strlen(p2);
    int ret, j, i = 0;

    while (i < len2) {
        ret = 0, j = 0;
        while (j != len1) {
            s3[i][j] = (((p2[len2 - 1 - i] - 48)        \
            * (p1[len1 - 1 - j]-48) + ret) % 10) + 48;
            ret = (((p2[len2 - 1 - i] - 48)             \
            * (p1[len1 - 1 - j] - 48) + ret) / 10);
            j++;
        }
        s3[i][j] = ret + 48;
        s3[i][j+1] = '\0';
        s3[i] = growstr(s3[i], len1 + i + 1);
        s3[i] = my_revstr(s3[i]);
        i++;
    }
    s3[i] = NULL;
    return (s3);
}
