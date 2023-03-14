/*
** EPITECH PROJECT, 2021
** dante (Workspace)
** File description:
** generator
*/

#include <stdlib.h>
#include "solver.h"
#include "my.h"

void get_map(sol_t *sol, char **map)
{
    int n = 0;
    int len;

    sol->map = malloc(sizeof(char *) * (sol->x + 2));
    len = my_strlen(*map) + 1;
    for (int i = 0; i < len; i += sol->x + 1, n++)
        sol->map[n] = my_strndupm(*map, i, i + sol->x);
    sol->map[n] = NULL;
    if (*map) free(*map);
}

static int check_values(sol_t *sol, char **av, int ac)
{
    int n = 1;
    char *map;

    if (ac != 2)
        return (1);
    map = read_file(av[1]);
    sol->y = sol->x = 0;
    for (int i = 0; map[i]; i++) {
        if (n && map[i] == '\n') {
            sol->x = i;
            n = 0;
        }
        if (map[i] == '\n') sol->y++;
    }
    sol->y++;
    if (sol->x <= 0 || sol->y <= 0)
        return (1);
    get_map(sol, &map);
    return (0);
}

int main(int ac, char **av)
{
    int return_code = 0;
    sol_t sol;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (error_handling(0));
    if (check_values(&sol, av, ac))
        return (error_handling(84));
    solve_maze(&sol, (cell_t){0, 0}, (cell_t){sol.x - 1, sol.y - 1});
    print_array_address(&sol.map);
    destroy_map(&sol);
    return (return_code);
}
