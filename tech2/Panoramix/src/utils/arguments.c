/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** arguments
*/

#include "pano.h"
#include "my.h"

int check_arguments(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        print_usage(stdout, av[0]);
        return (SUCCESS_CODE);
    }
    if (ac != 5) {
        print_usage(stderr, av[0]);
        print_error(av[0], "Invalid number of arguments\nUse -h for help\n");
        return (ERROR_CODE);
    }
    return (-1);
}

int init_arguments(pano_t *pano, char **av)
{
    args_t args;

    args.nb_villagers = my_getnbr(av[1]);
    args.pot_size = my_getnbr(av[2]);
    args.nb_fights = my_getnbr(av[3]);
    args.nb_refills = my_getnbr(av[4]);

    if (args.nb_villagers <= 0 || args.pot_size <= 0
    || args.nb_fights <= 0 || args.nb_refills <= 0) {
        print_usage(stderr, av[0]);
        fprintf(stderr, "Values must be >0.\n");
        return (1);
    }
    pano->nb_servings_left = args.pot_size;
    pano->args = args;
    return (0);
}
