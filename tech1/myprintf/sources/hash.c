/*
** EPITECH PROJECT, 2020
** hash precede
** File description:
** Precede o x and X with 0, 0x, 0X respectively if there is a #
*/

#include <stdarg.h>
#include "bsprintf.h"

void hash(va_list mem, int i, char const *expr)
{
    (expr[i] == '#') && (i++);
    (expr[i] == '%') && (i += 2);
    switch (expr[i]) {
        case 'x':
            my_putstr("0x");
            my_put_uns_hex_nbr(va_arg(mem, unsigned int));
            break;
        case 'X':
            my_putstr("0X");
            my_put_uns_hex_nbr_maj(va_arg(mem, unsigned int));
            break;
        case 'o':
            my_putstr("0");
            my_put_oct_nbr(va_arg(mem, unsigned int));
            break;
        default:
            return;
    }
    va_arg(mem, void *);
    return;
}