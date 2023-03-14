/*
** EPITECH PROJECT, 2020
** plus n plus
** File description:
** module for add
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *plus_n_plus(char *s1, char *s2, char *sf)
{
    int i;
    int j;
    int test;
    char *p1;
    char *p2;

    (s1[0] == 45) ? (p1 = onlynumb(s1)) : (p1 = s1);
    (s2[0] == 45) ? (p2 = onlynumb(s2)) : (p2 = s2);

    if (my_strlen(p1) < my_strlen(p2))
        p1 = growstr(p1, my_strlen(p2));
    if (my_strlen(p2) < my_strlen(p1))
        p2 = growstr(p2, my_strlen(p1));

    i = my_strlen(p1) - 1;
    j = my_strlen(p2) - 1;
    test = checksize(p1, p2);
    (s1[0] != '-' && s2[0] != '-') ? (sf = det1(i, j, p1, p2)) : 0;
    return sf;
}
