/*
** EPITECH PROJECT, 2020
** determinate quotient
** File description:
** de
*/

#include <unistd.h>
#include <stdlib.h>
#include "mymac.h"
#include "my.h"
#include "pers.h"

char *deter_quot(char *s, char *p1, char *res, char *p2)
{
    char *sum = malloc(sizeof(char) * (my_strlen(p1) + 5));
    char *b = "10";

    while (my_strlen(res) != my_strlen(p1)) {
        res = infin_mult(p2, s);
        s = infin_mult(s, b);
    }
    for (struct {int pos; int l;} v = {0, 0}; v.pos != my_strlen(s); v.pos++) {
        sum = infin_add("1", "1");
        for (v.l = 1; sum[0] != '-' && sum != "0"; v.l++) {
            s = targetstr(s, v.pos, v.l);
            res = infin_mult(p2, s);
            res = setminus(res);
            sum = infin_add(p1, res);
            if (v.l == 11)
                break;
        }
        (v.l == 11) ? (s[v.pos] = '9') : (s[v.pos] = v.l+46);
    }
    return s;
}
