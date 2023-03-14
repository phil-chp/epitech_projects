/*
** EPITECH PROJECT, 2020
** infin modulo
** File description:
** modulo
*/
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "mymac.h"
#include "pers.h"

char *infin_mod(char *nb1, char *nb2)
{
    char *t;
    char *s1 = retarg(nb1);
    char *s2 = retarg(nb2);
    char *p1 = prep(s1);
    char *p2 = prep(s2);
    char *k = malloc(sizeof(char) * (my_strlen(nb1)+2));

    if (checksize(p1, p2) == 1)
        return p1;
    t = malloc(sizeof(char) * (my_strlen(nb1) + 1));
    t = infin_div(nb1, nb2);
    if (t[0] == '\0' )
        return "";
    p2 = infin_mult(p2, t);
    if (p2[0] != '-')
        p2 = setminus(p2);
    k = infin_add(p1, p2);
    return k;
}
