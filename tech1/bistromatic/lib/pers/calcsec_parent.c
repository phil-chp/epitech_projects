/*
** EPITECH PROJECT, 2020
** Calcsec Parent
** File description:
** If there is a parenthesis it will call the
** function for additions and substractions.
*/

#include <stdlib.h>
#include "pers.h"

char **calcsec_parent(char **T, int k, int pp1, int pp2)
{
    k = checksec(T, pp1, pp2);
    if (compare(T[k], "+") == 1) {
        if ((pp2 - pp1) == 4) {
            T[k - 2] = infin_add(T[k - 1], T[k + 1]);
            return (module(change_tcrush(k, T)));
        } else {
            T[k - 1] = infin_add(T[k - 1], T[k + 1]);
            return (module(change_t(k, T)));
        }
    } else if (compare(T[k], "-") == 1) {
        T[k + 1] = setminus(T[k + 1]);
        if ((pp2 - pp1) == 4) {
            T[k - 2] = infin_add(T[k - 1], T[k + 1]);
            return (module(change_tcrush(k, T)));
        } else {
            T[k - 1] = infin_add(T[k - 1], T[k + 1]);
            return (module(change_t(k, T)));
        }
    }
    return (0);
}
