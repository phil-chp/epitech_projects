/*
** EPITECH PROJECT, 2020
** right indent
** File description:
** right indent according to number
** deals with n numbers up to INTMAX
*/

#include "bsprintf.h"

static int calc_indent(va_list mem, int n)
{
    char vals[12] = "iduoxXbpsSc%";
    void *arg = va_arg(mem, void *);

    for (int j = 0; j < 12; j++)
        if (j < 8) {
            n -= my_int_len(arg);
            j = 12;
        } else if (j > 7 && j < 10) {
            n -= my_strlen(arg);
            j = 12;
        } else if (j > 9 && j < 12){
            n -= 1;
            j = 12;
        }
    (n < 0) && (n = 0);
    return (n);
}

static int left_ident(va_list mem, int i, char const *expr)
{
    unsigned int p, res, n = 1;

    for (p = 0; expr[i] >= '0' && expr[i] <= '9'; i++) {
        p += expr[i] - '0';
        p *= 10;
        (p > 2147483647) && (p /= 10);
    }
    (p / 10 > 9) && (n = 2);
    (p / 10 > 99) && (n = 3);
    res = (i + (my_int_len(p / 10)) - n);
    p = calc_indent(mem, p) - 1;
    (p != 0 && p <= 2147483647) && (i--, space_adder(p / 10), 0);
    return (res);
}

static int right_ident(va_list mem, int i, char const *expr, unsigned int *p)
{
    int res, n = 1;

    for (*p = 0; expr[i] >= '0' && expr[i] <= '9'; i++) {
        *p += expr[i] - '0';
        *p *= 10;
        (*p > 2147483647) && (*p /= 10);
    }
    (*p != 0 && *p <= 2147483647) && (i--, *p /= 10);
    (*p > 9) && (n = 0);
    (*p > 99) && (n = 1);
    res = (i + (my_int_len(*p / 10)) - n);
    *p = calc_indent(mem, *p);
    return (res);
}

int indent_param(va_list mem, int i, char const *expr, unsigned int *p)
{
    int n = 0, m = i;
    (expr[i] == '%') && (i++);
    (expr[i] == '-') && (n = 1, i++);
    if (expr[i] == '0')
        return (i + 1);
    if (expr[i] >= '1' && expr[i] <= '9')
        if (n == 0)
            return left_ident(mem, i, expr);
        else if (n == 1)
            return right_ident(mem, i, expr, &*p);
    return (m + 2);
}