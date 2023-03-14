/*
** EPITECH PROJECT, 2020
** multiplication infinite
** File description:
** inf
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "pers.h"

char *infin_mult(char *nb1, char *nb2)
{
    char *s1 = retarg(nb1);
    char *s2 = retarg(nb2);
    char *p1 = prep(s1);
    char *p2 = prep(s2);
    char **s3;
    char *res;

    if (my_strlen(p1) <= my_strlen(p2))
        p1 = growstr(p1, my_strlen(p2)+1);
    res = malloc(sizeof(char)*(my_strlen(p1)*2));
    s3 = malloc(sizeof(char *)* (my_strlen(p2) + 1));
    for (int i = 0; i != my_strlen(p1); i++)
        s3[i] = malloc(sizeof(char) * (my_strlen(p1) * 2 + 2));
    s3 = mult_res_mult(p1, p2, s3);
    res = add_res_multi(s3, my_strlen(p2), res);
    res = retirezero(res);
    return (putminus(s1, s2, res));
}
