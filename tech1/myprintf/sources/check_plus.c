/*
** EPITECH PROJECT, 2020
** Check plus
** File description:
** Check plus value for d i o u x X
*/

#include "bsprintf.h"

static int check_plus_two(va_list mem, int i, char const *expr)
{
    int num, caps = 1;

    switch (expr[i + 1]) {
        case 'x':
            num = va_arg(mem, unsigned int);
            (num >= 0) && (my_putchar('+'), 0);
            my_put_uns_hex_nbr(num);
        case 'X':
            num = va_arg(mem, unsigned int);
            (num >= 0) && (my_putchar('+'), 0);
            my_put_uns_hex_nbr_maj(num);
            return (1);
        case 'o':
            num = va_arg(mem, int);
            (num >= 0) && (my_putchar('+'), 0);
            my_put_oct_nbr(num);
            return (1);
    }
    return (0);
}

int check_plus_one(va_list mem, int i, char const *expr)
{
    int num = 0;

    switch (expr[i + 1]) {
        case 'd':
            (1 != 1) && (0);
        case 'i':
            num = va_arg(mem, int);
            (num >= 0) && (my_putchar('+'), 0);
            my_put_nbr(num);
            return (1);
        case 'u':
            my_putchar('+');
            my_put_uns_nbr(va_arg(mem, unsigned int));
            return (1);
    }
    num = check_plus_two(mem, i, expr);
    return (num);
}
