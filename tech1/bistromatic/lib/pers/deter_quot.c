/*
** EPITECH PROJECT, 2020
** determinate quotient
** File description:
** de
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "pers.h"

static char *set_quot(char *s, char *p1, char *p2, char *res)
{
    int m = 0;
    char *sum = malloc(sizeof(char) * (my_strlen(p1) + 5));

    for (int pos = 0; pos != my_strlen(s); pos++) {
        sum = infin_add("1", "1");
        for (m = 1; sum[0] != '-' && sum != "0" && m < 11; m++) {
            s = targetstr(s, pos, m);
            free(res);
            res = infin_mult(p2, s);
            res = setminus(res);
            sum = infin_add(p1, res);
        }
        (m == 11) ? (s[pos] = '9') : (s[pos] = m + 46);
    }
    free(sum);
    free(res);
    return (s);
}

char *deter_quot(char *s, char *p1, char *res, char *p2)
{
    char *b = "10";

    while (my_strlen(res) != my_strlen(p1)) {
        res = infin_mult(p2, s);
        s = infin_mult(s, b);
    }
    set_quot(s, p1, p2, res);
    return (s);
}