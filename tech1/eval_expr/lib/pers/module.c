/*
** EPITECH PROJECT, 2020
** Module
** File description:
** This is the main module that calls for
** every action that accounts to calculations
*/

#include <unistd.h>
#include "mymac.h"
#include "pers.h"
#include "my.h"

char **module(char **T)
{
    int test = 0;
    int pp1 = open_parent(T);
    int pp2 = close_parent(T);
    int k = 0;

    if (T[0][0] == '(' && T[2][0] == ')' && T[3] == 0) {
        my_swap_str(&T[0], &T[1]);
        return (T);
    }
    while (T[test])
        test++;
    if (test == 1)
        return (T);
    if ((pp1 == 0 && pp2 != 0) || (pp1 != 0 && pp2 == 0)) {
        ERROR;
        return (0);
    }
    (pp1 != 0 && pp2 != 0) ? first_module(T, k, pp1, pp2) : 0;
    (pp1 == 0 && pp2 == 0) ? second_module(T, k, pp1, pp2) : 0;
    return (0);
}
