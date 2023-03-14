/*
** EPITECH PROJECT, 2021
** matchstick
** File description:
** create_map
*/

#include <stdlib.h>
#include "my.h"

static char **populate_map(char **map, int h)
{
    int match = 0;

    for (int i = 1; match <= h - 1 && i <= h; i++, match++)
        for (int j = h - match; j <= h + match; j++)
            map[i][j] = '|';
    return (map);
}

char **create_map(int h)
{
    char **map;
    int w;

    w = h * 2;
    map = malloc(sizeof(char *) * (h + 3));
    map[0] = my_strndup('*', w);
    for (int i = 1; i <= h; i++)
        map[i] = my_strndup_frame('*', ' ', w);
    map[h + 1] = my_strndup('*', w);
    map[h + 2] = NULL;
    map = populate_map(map, h);
    return (map);
}
