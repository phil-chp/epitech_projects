/*
** EPITECH PROJECT, 2021
** clean_str
** File description:
** main
*/

#include <stdlib.h>
#include "includes/utils.h"
#include "includes/errors.h"
#include "includes/my.h"

int main(int ac, char **av)
{
    char *formatted_string;

    if (ac != 2) {
        NOT_ENOUGH_ARGS;
        return (84);
    }
    formatted_string = my_formatter(av[1]);
    my_putstr(formatted_string);
    my_putstr("\n");
    return (0);
}
