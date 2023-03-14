/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include <stdlib.h>
#include "errors.h"
#include "struct.h"
#include "my.h"

static int error_handling(int ac)
{
    if (ac < 2) {
        ARGS_ERROR;
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (error_handling(ac) == 84)
        return (84);
    int nums[ac - 1];

    for (int i = 0; i + 1 < ac; i++)
        nums[i] = my_getnbr(av[i + 1]);

    sorter(ac - 1, nums);
    return (0);
}
