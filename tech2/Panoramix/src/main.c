/*
** EPITECH PROJECT, 2022
** Panoramix (Workspace)
** File description:
** main
*/

#include "pano.h"

int main(int ac, char **av)
{
    int return_code;
    pano_t pano;

    if ((return_code = check_arguments(ac, av)) >= 0) return (return_code);
    if (init_arguments(&pano, av))     return (ERROR_CODE);
    if (init_panoramix(&pano, av[0]))  return (ERROR_CODE);
    if (start_panoramix(&pano, av[0])) return (ERROR_CODE);
    destroy_panoramix(&pano);
    return (SUCCESS_CODE);
}
