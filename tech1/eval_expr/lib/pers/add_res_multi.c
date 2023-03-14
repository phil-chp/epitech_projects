/*
** EPITECH PROJECT, 2020
** add result of multi
** File description:
** module for multi
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "pers.h"

char *add_res_multi(char **s3, int len2, char *res)
{
    int i = 0;
    int ref;
    int x = 0;
    int z = 0;

    while (s3[i])
        i++;
    ref = my_strlen(s3[i-1]);
    while (x != i-1) {
        s3[x] = growstr(s3[x], ref);
        x++;
    }
    res = s3[0];
    while (z+1 < len2) {
        res = infin_add(res, s3[z+1]);
        z++;
    }
    return (res);
}
