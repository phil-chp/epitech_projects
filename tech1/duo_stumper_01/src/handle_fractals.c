/*
** EPITECH PROJECT, 2021
** fractals
** File description:
** handle_fractals
*/

#include "fractals.h"
#include "my.h"

static int print_map(char **av)
{
    char **array;

    array = my_str_to_word_array(av[2]);
    for (int i = 0; array[i];i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
    return (0);
}

int handle_fractals(char **av)
{
    int nbr;

    nbr = my_getnbr(av[1]);
    if (nbr == 0)
        write(1, "#\n", 2);
    else if (nbr == 1) {
        if (print_map(av) == 84)
            return (84);
    }
    else
        create_fractals(av, nbr);
    return (0);
}
