/*
** EPITECH PROJECT, 2020
** Second Module
** File description:
** Second part of the module function, calls
** calc functions that don't have parenthesis
*/

#include "pers.h"

char **second_module(char **T, int k, int pp1, int pp2)
{
    int b = 0;

    while (T[b] != 0)
        b++;
    pp2 = b;
    if (checkprim(T, pp1, pp2) == 0)
        calcsec(T, k, pp1, pp2);
    else
        calcprim(T, k, pp1, pp2);
    return (0);
}
