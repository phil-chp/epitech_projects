/*
** EPITECH PROJECT, 2020
** reduc 0
** File description:
** reduc all 0 in front of str
*/
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *putminus(char *s1, char *s2, char *mul)
{
    int g;

    if (s1[0] == '-' && s2[0] == '-')
        return mul;
    if (s1[0] == '-' && s2[0] == '-')
        return mul;
    if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-')) {
        mul = my_revstr(mul);
        g = my_strlen(mul);
        mul[g] = '-';
        mul[g + 1] = '\0';
        mul = my_revstr(mul);
    }
    free(s1);
    free(s2);
    return (mul);
}
