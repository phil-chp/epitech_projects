/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** error_handling
*/

#include <unistd.h>
#include "matchstick.h"
#include "my.h"

void usage(void)
{
    write(2, "USAGE\n\t./matchstick h max\n\n", 28);
    write(2, "DESCRIPTION\n\th\tHeight of the map 2 <= h <= 99\n", 47);
    write(2, "\tmax\tMax number of matches to remove\n", 38);
    write(2, "\t   \tper turn, max > 0\n", 24);
}

int error_handling(int ac, char **av)
{
    int height;
    int max;

    if (ac != 3) {
        write(2, "matchstick: Bad number of parameters\n", 38);
        usage();
        return (ERROR);
    }
    height = my_getnbr(av[1]);
    max = my_getnbr(av[2]);
    if (height < 2 || height > 99 || max < 1) {
        write(2, "matchstick: Bad parameters\n", 28);
        usage();
        return (ERROR);
    }
    return (0);
}
