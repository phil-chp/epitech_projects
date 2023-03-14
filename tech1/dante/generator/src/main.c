/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** generator
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"

static int check_values(gen_t *gen, char **av, int ac)
{
    int x;
    int y;

    if (ac < 3 || ac > 4)
        return (1);
    x = my_getnbr(av[1]);
    y = my_getnbr(av[2]);
    if (x <= 0 || y <= 0)
        return (1);
    gen->x = x;
    gen->y = y;
    gen->perfect = (ac == 4 && my_strcmp(av[3], "perfect") == 0 ? true : false);
    gen->map = NULL;
    return (0);
}

int main(int ac, char **av)
{
    int return_code = 0;
    gen_t gen;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (error_handling(0));
    if (check_values(&gen, av, ac))
        return (error_handling(84));
    if (gen.y == 1) {
        printf("*");
        return (0);
    }
    if (create_empty_maze(&gen))
        return (84);
    srand(time(NULL));
    generate_maze(&gen);
    print_array_address(&gen.map);
    destroy_map(&gen);
    return (return_code);
}
