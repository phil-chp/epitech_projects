/*
** EPITECH PROJECT, 2020
** Main
** File description:
** Bistro-matic Main
*/

#include "my.h"
#include "eval_expr_struct.h"

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
