/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Bistro-matic Main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"
#include "eval_expr_struct.h"
#include "mymain.h"
#include "pers.h"

static char *get_expr(unsigned int size)
{
    t_eval *eval;
    char *expr;

    if (size <= 0) {
        SYNTAX_ERROR_MSG;
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * (size + 1));
    if (expr == 0) {
        ERROR_MSG;
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        ERROR_MSG;
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        SYNTAX_ERROR_MSG;
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        SYNTAX_ERROR_MSG;
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    eval_expr(av[1], av[2], expr, size);
    return (EXIT_SUCCESS);
}
