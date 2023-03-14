/*
** EPITECH PROJECT, 2020
** First Module
** File description:
** First part of the module function, calls
** calc functions that have parenthesis
*/

#include <stdlib.h>
#include "pers.h"

char **first_module(char **T, int k, int pp1, int pp2)
{
    if (checkprim(T, pp1, pp2) == 0) {
        if (checksec(T, pp1, pp2) == 0)
            return (module(change_t(pp1, T)));
        else
            calcsec_parent(T, k, pp1, pp2);
    } else
        calcprim_parent(T, k, pp1, pp2);
    return (0);
}
