/*
** EPITECH PROJECT, 2020
** minus n plus
** File description:
** module for add
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "pers.h"

char *minus_n_plus(char *s1, char *s2, char *sf)
{
    int i, j, test;
    char *p1 = NULL, *p2 = NULL;

    (s1[0] == 45) ? (p1 = onlynumb(s1)) : (p1 = my_strdup(s1));
    (s2[0] == 45) ? (p2 = onlynumb(s2)) : (p2 = my_strdup(s2));
    (my_strlen(p1) < my_strlen(p2)) && (p1 = growstr(p1, my_strlen(p2)));
    (my_strlen(p2) < my_strlen(p1)) && (p2 = growstr(p2, my_strlen(p1)));
    i = my_strlen(p1) - 1;
    j = my_strlen(p2) - 1;
    test = checksize(p1, p2);
    (s1[0] == '-' && s2[0] != '-' && test == 0) ? (sf = det3(i, j, p1, p2)) : 0;
    (s1[0] == '-' && s2[0] != '-' && test == 2) ? (sf = det4(i, j, p2, p1)) : 0;
    (s1[0] == '-' && s2[0] != '-' && test == 1) ? (sf = det3(i, j, p1, p2)) : 0;
    free(p1);
    free(p2);
    return (sf);
}