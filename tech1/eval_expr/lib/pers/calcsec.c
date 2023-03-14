/*
** EPITECH PROJECT, 2020
** Calcsec
** File description:
** If there is no parenthesis it will call the
** function for additions and substractions.
*/

#include "pers.h"

char **calcsec(char **T, int k, int pp1, int pp2)
{
    if (checksec(T, pp1, pp2) == 0) {
        return (module(change_t(k, T)));
    } else {
        k = checksec(T, pp1, pp2);
        if (compare(T[k], "+") == 1) {
            T[k - 1] = infin_add(T[k - 1], T[k + 1]);
            return (module(change_t(k, T)));
        } else if (compare(T[k], "-") == 1) {
            T[k + 1] = setminus(T[k + 1]);
            T[k - 1] = infin_add(T[k - 1], T[k + 1]);
            return (module(change_t(k, T)));
        }
    }
    return (0);
}
