/*
** EPITECH PROJECT, 2020
** check short
** File description:
** check short i d o u x X
*/

#include "bsprintf.h"

static int check_short_two(va_list mem, int i, char const *expr)
{
    int num, caps = 1;

    switch (expr[i + 1]) {
        case 'x':
            caps = 0;
        case 'X':
            my_put_uns_hex_nbr(va_arg(mem, unsigned int));
            return (1);
        case 'o':
            my_put_oct_nbr(va_arg(mem, int));
            return (1);
    }
    return (0);
}

int check_short_one(va_list mem, int i, char const *expr)
{
    int num = 0;

    switch (expr[i + 1]) {
        case 'd':
            (1 != 1) && (0);
        case 'i':
            my_put_short_nbr(va_arg(mem, int));
            return (1);
        case 'u':
            my_put_uns_nbr(va_arg(mem, unsigned int));
            return (1);
    }
    num = check_short_two(mem, i, expr);
    return (num);
}