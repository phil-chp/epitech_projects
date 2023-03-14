/*
** EPITECH PROJECT, 2020
** addit
** File description:
** return a str result of addition and substra..
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *infin_add(char *nb1, char *nb2)
{
    char *s1 = NULL;
    char *s2 = NULL;
    char *sf = malloc(sizeof(char)*(my_strlen(nb1)+my_strlen(nb2)));
    s1 = retarg(nb1);
    s2 = retarg(nb2);

    sf = plus_n_plus(s1, s2, sf);
    sf = minus_n_minus(s1, s2, sf);
    sf = minus_n_plus(s1, s2, sf);
    sf = plus_n_minus(s1, s2, sf);

    return sf;
}
