/*
** EPITECH PROJECT, 2020
** section addition
** File description:
** partie de l'addition
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *section_add(char *s1, char *s2, char *sf)
{
    s2 = plus_n_plus(s1, s2, sf);
    s2 = minus_n_minus(s1, s2, sf);
    s2 = minus_n_plus(s1, s2, sf);
    s2 = plus_n_minus(s1, s2, sf);
    return s2;
}
