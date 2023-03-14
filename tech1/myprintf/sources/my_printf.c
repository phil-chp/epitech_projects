/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Main file
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsprintf.h"
#include "param_caller.h"

static int my_indent(char const *expr, int i, va_list mem, int *p)
{
    if (expr[i + 1] == '-' || (expr[i + 1] >= '0' && expr[i + 1] < ':')) {
        *p = 0;
        i = indent_param(mem, i, expr, &*p);
        i--;
    }
    return (i);
}

static int my_modifiers(char const *expr, int i, va_list mem, int *j)
{
    char mods[5] = "#+ hl";
    int n = 0;
    for (n = 0; n < 5; n++)
        if (mods[n] == expr[i + 1]) {
            modifiers[n](mem, i + 1, expr);
            n = 6;
            i += 2;
        }
    *j = n;
    return (i);
}

static int my_parameters(char const *expr, int i, va_list T, int *j)
{
    char params[13] = "cdisuoxXbSp%n";

    for (int k = 0; k < 13; k++)
        if (*j >= 6) {
            if (params[k] == expr[i + 1]) {
                parameters[k](va_arg(T, const void *));
                k = 14;
                i++;
            }
        } else {
            if (params[k] == expr[i + 1]) {
                parameters[k](va_arg(T, const void *));
                k = 14;
                i++;
            }
        }
    return (i);
}

int my_printf(char const *expr, ...)
{
    va_list T;
    va_list mem;
    int p = 0, j = 0;
    int i;
    va_start(T, expr);
    va_copy(mem, T);

    if (expr[0] == '\0') return (0);
    for (i = 0; i + 1 <= my_strlen(expr); i++) {
        if (expr[i] == '%') {
            i = my_indent(expr, i, mem, &p);
            i = my_modifiers(expr, i, mem, &j);
            i = my_parameters(expr, i, T, &j);
            (p > 0) && (space_adder(p), 0);
        } else
            my_putchar(expr[i]);
    }
    va_end(T);
    return (0);
}