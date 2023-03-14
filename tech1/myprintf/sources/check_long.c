/*
** EPITECH PROJECT, 2020
** check long
** File description:
** check long for i d o u x X
*/

#include "bsprintf.h"

static int check_long_two(va_list mem, int i, char const *expr)
{
    int num, caps = 1;

    switch (expr[i + 1]) {
        case 'x':
            caps = 0;
        case 'X':
            my_put_uns_hex_nbr(va_arg(mem, unsigned long int));
            return (1);
        case 'o':
            my_put_oct_nbr(va_arg(mem, long int));
            return (1);
    }
    return (0);
}

int check_long_one(va_list mem, int i, char const *expr)
{
    int num = 0;

    switch (expr[i + 1]) {
        case 'd':
            (1 != 1) && (0);
        case 'i':
            my_put_long_nbr(va_arg(mem, long int));
            return (1);
        case 'u':
            my_put_long_uns_nbr(va_arg(mem, unsigned long int));
            return (1);
    }
    num = check_long_two(mem, i, expr);
    return (num);
}