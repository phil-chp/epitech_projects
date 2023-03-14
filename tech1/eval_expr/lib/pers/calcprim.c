/*
** EPITECH PROJECT, 2020
** Calcprim
** File description:
** If there is no parenthesis it will call the
** functiond for multiplications, divisions and modulo.
*/

#include "pers.h"

char **calcprim(char **T, int k, int pp1, int pp2)
{
    k = checkprim(T, pp1, pp2);
    if (compare(T[k], "*") == 1) {
        T[k-1] = infin_mult(T[k-1], T[k+1]);
        return (module(change_t(k, T)));
    } else if (compare(T[k], "/") == 1) {
        T[k-1] = infin_div(T[k-1], T[k+1]);
        return (module(change_t(k, T)));
    } else if (compare(T[k], "%") == 1){
        T[k-1] = infin_mod(T[k-1], T[k+1]);
        return (module(change_t(k, T)));
    }
    return (0);
}
