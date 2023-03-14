/*
** EPITECH PROJECT, 2020
** Infin Add
** File description:
** Returns a str result of addition or substraction
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *infin_add(char *nb1, char *nb2)
{
    char *sf = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)));
    char *s1 = retarg(nb1);
    char *s2 = retarg(nb2);

    sf = minus_n_minus(s1, s2, sf);
    sf = plus_n_plus(s1, s2, sf);
    sf = minus_n_plus(s1, s2, sf);
    sf = plus_n_minus(s1, s2, sf);
    free(s1);
    free(s2);
    return (sf);
}