/*
** EPITECH PROJECT, 2021
** duostumper2
** File description:
** handle_neighboors
*/

#include "gameoflife.h"

static int check_for_out_of_bounds(char **map, int di, int dj)
{
    int len_di;
    int len_dj;

    if (di < 0 || dj < 0)
        return (0);
    len_di = length_array(map) - 1;
    if (di > len_di)
        return (0);
    len_dj = strlen(map[di]);
    if (dj > len_dj)
        return (0);
    return (1);
}

static void increment_count(char **map, int i, int j, int *n_count)
{
    if (check_for_out_of_bounds(map, i, j))
        if (map[i][j] == 'X') (*n_count)++;
}

static int get_neighboor_count(char **map, int i, int j)
{
    int n_count;

    n_count = -1;
    for (int di = -1; di < 2; di++) {
        for (int dj = -1; dj < 2; dj++) {
            if (di == 0 && dj == 0) continue;
            increment_count(map, i + di, j + dj, &n_count);
        }
    }
    if (n_count != -1) n_count++;
    return (n_count);
}

char check_neighbors(char **map, int i, int j)
{
    int n_count;

    n_count = get_neighboor_count(map, i, j);
    if (n_count == 3)
        return ('X');
    if (n_count == 0 || n_count == 1 || (n_count >= 4 && n_count <= 8))
        return ('.');
    return (map[i][j]);
}
