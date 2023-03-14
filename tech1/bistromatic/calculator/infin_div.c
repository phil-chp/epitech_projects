/*
** EPITECH PROJECT, 2020
** Infin Div
** File description:
** Returns a string with the result of the divsion
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

char *infin_div(char *nb1, char *nb2)
{
    char *s1 = retarg(nb1), *s2 = retarg(nb2), *p1 = prep(s1), *p2 = prep(s2);
    char *s = malloc(sizeof(char) * (my_strlen(p1) + 2));
    char *res = malloc(sizeof(char) * (my_strlen(p1) * 2));

    s = "1", res = "0";
    check_error(p2);
    p2 = setminus(p2);
    if (infin_add(p1, p2)[0] == '-')
        return ("0");
    p2 = onlynumb(p2);
    if (my_strlen(p1) == 1 && my_strlen(p2) == 1)
        p1 = growstr(p1, my_strlen(p2) + 1);
    s = deter_quot(s, p1, res, p2);
    res = infin_mult(p2, infin_add(s, "1"));
    (my_strcmp(p1, res) == 0) ? (s = infin_add(s, "1")) : 0;
    s = retirezero(s);
    s = putminus(s1, s2, s);
    free(p2);
    return (s);
}