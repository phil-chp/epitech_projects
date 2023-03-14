/*
** EPITECH PROJECT, 2021
** duostumper2
** File description:
** gameoflife
*/

#include "gameoflife.h"

int gameoflife(char **map, int itr)
{
    char **temp;

    temp = array_dup(map);
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++)
            temp[i][j] = check_neighbors(map, i, j);
    map = temp;
    if (itr > 1)
        gameoflife(map, itr - 1);
    else
        my_print_map(map);
    my_free_array(map);
    return (0);
}
