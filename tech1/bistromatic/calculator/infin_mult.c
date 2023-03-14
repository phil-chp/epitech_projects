/*
** EPITECH PROJECT, 2020
** Infin Mult
** File description:
** Returns a string with the result of the multiplication
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *infin_mult(char *nb1, char *nb2)
{
    char *s1 = retarg(nb1);
    char *s2 = retarg(nb2);
    char *p1 = prep(s1);
    char *p2 = prep(s2), *res;
    char **s3;
    int i;

    if (my_strlen(p1) <= my_strlen(p2))
        my_swap_str(&p1, &p2);
    res = malloc(sizeof(char) * (my_strlen(p1) * 2));
    s3 = malloc(sizeof(char *) * (my_strlen(p1) + 1));
    for (i = 0; i <= my_strlen(p2); i++)
        s3[i] = malloc(sizeof(char) * (my_strlen(p1) * 2 + 2));
    s3 = mult_res_mult(p1, p2, s3);
    res = add_res_multi(s3, my_strlen(p2), res);
    res = retirezero(res);
    free(s3);
    return (putminus(s1, s2, res));
}